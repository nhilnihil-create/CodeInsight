#include <stdio.h>

int main(){
    int a[4],b[4],i,A,B;
    A=0;
    B=0;
    for (i=0;i<4;i++) {
        scanf("%d",&a[i]);
        A+=a[i];
    }
    for (i=0;i<4;i++) {
        scanf("%d",&b[i]);
        B+=b[i];
    }
    if (A>=B) {printf("%d\n",A);}
    else {printf("%d\n",B);}
    return 0;
}