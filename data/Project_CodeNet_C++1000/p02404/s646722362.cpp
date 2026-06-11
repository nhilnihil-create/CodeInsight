#include <stdio.h>

int main (void) {

	int x, y;
	int i, j;

	while (1){
		if (x+y==0)
			break;
		scanf("%d %d", &x, &y);
		for (j=0; j<x; j++){
			for(i=0; i<y; i++){
				if( j==0 || j==x-1 || i==0 || i==y-1 ){
					printf("#");
				} else {
					printf(".");
				}
			}
		printf("\n");
		}
	if (x+y != 0)
		printf("\n");
	}
	return 0;
}