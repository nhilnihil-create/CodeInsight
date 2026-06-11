#include<cstdio>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    -500<=a,b>=500;
    if(a<b){
     printf("a < b\n");
    }else if(a>b){
     printf("a > b\n");
    }else if(a==b){
     printf("a == b\n");
    }
    return 0;
}