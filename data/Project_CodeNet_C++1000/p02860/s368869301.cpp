#include <stdio.h>

int main () {
	int ang, akk = -1;
	char word[255];
	scanf ("%d", &ang);
	scanf ("%s", word);
	int x = ang / 2;
	if (ang % 2 == 0) {
		for (int i = 0; i < x; i++) {
			if (word[i] != word[x+i]) {
				akk = 1;
				break;
			} else {
				akk = 0;
			}		
		}
	} else printf ("No");
	
	if (akk == 0) {
		printf ("Yes");
	} else if (akk == 1) {
		printf ("No");
	}
	return 0;
}