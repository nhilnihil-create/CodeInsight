#include <stdio.h>

int main()
{
    int h, w, n, j, hasil=0;
    scanf("%d%d%d", &h,&w,&n);
    if(h>w){
        j=h;
    }else{
        j=w;
    }
    for(int i=0;i<n;i=i+j){
        hasil++;
    }
    printf("%d\n", hasil);
    return 0;
}