#include<stdio.h>
int main()
{
    int h,w,n,omen;
    scanf("%d %d %d",&h,&w,&n);
    if(h > w) omen = h;
    else omen = w;
    int hitung = 1;
    for(int i = omen;i<n;i += omen)
    hitung++;
    printf("%d\n",hitung);
    return 0;
}