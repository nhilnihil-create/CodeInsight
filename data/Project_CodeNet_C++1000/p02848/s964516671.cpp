#include <stdio.h>
#include <string.h>

//ABCXYZ 2
//012345
//CDEZAB
int main () {
	int n;
	scanf ("%d", &n);
	char word[10001];
	scanf ("%s", word);
	int pnjg = strlen(word);
	for (int i = 0; i < pnjg; i++) {
		word[i] += n;
		if (word[i] > 'Z') {
			word[i] -= 26;
		}
		printf ("%c", word[i]);	
	}
	
	return 0;
}