#include <stdio.h>

int main(void)
{
    int h, w, i, j, flag;

    scanf("%d %d", &h, &w);
    while((h!=0) && (w!=0)) {
        for(i=0;i<h;i++) {
            if (i % 2 == 1)
                flag = 1;
            else if (i % 2 == 0)
                flag = 0;
            for(j=0;j<w;j++) {
                if(flag == 0) {
                    printf("#");
                    flag = 1;
                } else if(flag==1) {
                    printf(".");
                    flag = 0;
                }
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d", &h, &w);
    }   
    return 0;
}