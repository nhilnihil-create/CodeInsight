#include <cstdio>

void printFrame(int h, int w)
{
    for(int y = 0; y < h; ++y){
        for(int x = 0; x < w; ++x){
            if(y == 0 || y == h-1 || x == 0 || x == w-1){
                printf("#");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    while(true){
        int h, w;
        scanf("%d %d", &h, &w);
        if(h == 0 && w == 0){
            break;
        }
        printFrame(h, w);
    }
    return 0;
}