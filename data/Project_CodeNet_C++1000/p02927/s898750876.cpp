#include <stdio.h>

int main(void){
    int m,d;
    int i,j,k;
    int d1,d10;
    int count=0;

    scanf("%d %d",&m,&d);

    for(i=22;i<=d;i++){
        d1=i/10;
        d10=i%10;
        if(d1>=2 && d10>=2){
            if(d1*d10<=m){
                count++;
            }
        }
    }

    printf("%d\n",count);

    return 0;
}