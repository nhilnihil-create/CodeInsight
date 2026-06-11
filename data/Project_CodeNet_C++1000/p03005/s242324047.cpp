#include<stdio.h>
int main(){
    int n,k,a,R;
    scanf("%d",&n);
    scanf("%d",&k);
    if(k==1){
        R=0;
    }
    else{
        R=n-(k-1)-1;
        }
    printf("%d",R);
    return 0;
}
