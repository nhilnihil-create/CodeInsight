#include <stdio.h>
void sh(int x, int y);
 
int main(void){
	while(1) {
        int h, w, x, y;
        scanf("%d %d", &h, &w);
        if (h == 0 & w == 0) {
            return 0;
        }
        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
                sh(x, y);
            }
            printf("\n");
        }
        printf("\n");
    }
}
 
void sh(int x, int y)
{
    if (x % 2) {
        if (y % 2) {
            printf("#");
        } else {
            printf(".");
        }
    } else {
        if (y % 2) {
            printf(".");
        } else {
            printf("#");
        }
    }
}