#include <stdio.h>
int main(){
	int pages;
	scanf("%d", &pages);
	(pages % 2 == 0) ? printf("%d", pages / 2) : printf("%d", pages / 2 + 1);
	return 0;
}
