#include <stdio.h>
#include <string.h>

int main () {
	char ans[5];
	
	scanf ("%s",ans);
	
		if (!strcmp ("ARC", ans)) {
			printf ("ABC\n");
		}
		if (!strcmp ("ABC", ans)) {
			printf ("ARC\n");
		}
	
	return 0;
}