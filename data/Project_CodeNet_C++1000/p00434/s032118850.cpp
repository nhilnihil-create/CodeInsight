#include <stdio.h>

int main(){
    int a[28],i,j,x[30];
    for (i=0;i<28;i++) {
        scanf("%d",&a[i]);
    }
    for (i=1;i<=30;i++) {
        x[i]=0;
        for (j=0;j<28;j++) {
            if (a[j]==i) {x[i]=1;}
        }
    }
    for (i=1;i<=30;i++) {
        if (x[i]==0) {
            printf("%d\n",i);
        }
    }
    return 0;
}