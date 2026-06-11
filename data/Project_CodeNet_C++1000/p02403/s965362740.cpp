#include <stdio.h>
 
void drawRectangle(int height, int width);

int main(void) {
 
    int i;
    int j;
    int width;
    int height;
 
    while(1) {
        scanf("%d %d", &height, &width);
         
        if(width == 0 && height == 0) {
            break;
        }

        drawRectangle(height, width);

        printf("\n");
    } 
 
    return 0;
}

void drawRectangle(int height, int width) {

    int i;
    int j;
    
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            putchar('#');
        }
        printf("\n");
    }

    return;
}