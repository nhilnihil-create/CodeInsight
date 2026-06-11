#include<stdio.h>
int main(){
    int a,b,o;
    while(1){
        scanf("%d %c%d",&a,&o,&b);
        if (o=='?')break;
        else if (o=='+'){
            printf("%d",a+b);
        }
        else if (o=='-'){
            printf("%d",a-b);
        }
        else if (o=='*'){
            printf("%d",a*b);
        }
        else if (o=='/'){
            printf("%d",a/b);
        }
        printf("\n");
    }
    return 0;
}