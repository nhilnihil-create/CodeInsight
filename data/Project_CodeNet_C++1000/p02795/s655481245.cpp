#include <stdio.h>

int main(){

    int total=0;
    int count=0;
    int rows;
    scanf("%d", &rows);
    int columns;
    scanf("%d", &columns);
    int blokHitam;
    scanf("%d", &blokHitam);
    while(total<blokHitam){
        if(rows>=columns){
            total+=rows;
//            printf("sekarang total blok hitam= %d\n", total);
        }
        else if(columns>=rows){
            total+=columns;
//            printf("sekarang total blok hitam= %d\n", total);
        }
    count++;
    }
printf("%d\n", count);

    return 0;
}