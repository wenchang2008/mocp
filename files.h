#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include "playlist.h"

struct file_list
{
	int num;		/* Number of elements on the list */
	int allocated;		/* Number of allocated elements */
	char **items;
};

int read_directory (const char *directory, struct file_list *dirs,
		struct file_list *playlists, struct plist *plist);
int read_directory_recurr (const char *directory, struct plist *plist,
		const int check_duplicates);
void resolve_path (char *buf, const int size, const char *file);
char *ext_pos (const char *file);
void file_list_free (struct file_list *list);
struct file_list *file_list_new ();
enum file_type file_type (const char *file);
int is_url (const char *str);
char *read_line (FILE *file);
void iconv_init ();
void iconv_cleanup ();
char *iconv_str (char *str, const int for_file_name);
char *find_match_dir (char *dir);
int file_exists (const char *file);
time_t get_mtime (const char *file);
struct file_tags *read_file_tags (const char *file,
		struct file_tags *present_tags, const int tags_sel);
void switch_titles_file (struct plist *plist);
void switch_titles_tags (struct plist *plist);

#endif
