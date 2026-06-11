#include <stdio.h>
int main(void)
{
    int h, w;
    while (1) {
	scanf("%d %d", &h, &w);
	if (h == 0 && w ==0) {
	    break;
	} else {
	    for (int i = 0; i < w; i ++) {
		printf("#");
	    }
	    printf("\n");
	    for (int j = 0; j < h - 2; j ++) {
		printf("#");
		for (int i = 0; i < w - 2; i ++) {
		    printf(".");
		}
		printf("#\n");
	    }
	    for (int i = 0; i < w; i ++) {
		printf("#");
	    }
	    printf("\n\n");
	}
    }
    return 0;
}