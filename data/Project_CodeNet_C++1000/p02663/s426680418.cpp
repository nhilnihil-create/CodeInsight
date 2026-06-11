#include <stdio.h>

int main () {
    int H,M,h,m,K;
    scanf("%d%d%d%d%d", &H,&M,&h,&m,&K);

    int jumlah= ((h-H)*60) + (m-M) -K;
    printf("%d", jumlah);




}