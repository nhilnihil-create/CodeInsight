#include<stdio.h>

int main(){
    
    int a,b,c,d,e;
    scanf("%d",&a);
    b = a%10;
    c = a/10;
    d = c%10;
    e = c/10;   
    if(b == 7){
        printf("Yes");
    }
    else if(d == 7){
        printf("Yes");
    }
    else if(e == 7){
        printf("Yes");
    }
    else{
        printf("No");
    }
    
    return 0;
}