#include<iostream>
#include<stdio.h>

void Range(int a, int b, int c);

int main(){
    int a, b, c;
    
    scanf("%d %d %d",&a,&b,&c);
    Range(a, b, c);
    
    return 0;
}

void Range(int a, int b, int c){
    if(a<b && b<c) printf("Yes\n");
    else printf("No\n");
}
