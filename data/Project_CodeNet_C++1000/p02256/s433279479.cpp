#include<stdio.h>
void int_swap(int *a, int *b){
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}
int gcd(int a, int b){
    int c;
    c=a%b;
    if(c==0) return b;
    if(c==1) return 1;
    gcd(b,c);
}

main(){
    int i,j,k;
    scanf("%d %d",&i,&j);
    if(i<j) int_swap(&i,&j);
    printf("%d\n",gcd(i,j));
    return 0;
}