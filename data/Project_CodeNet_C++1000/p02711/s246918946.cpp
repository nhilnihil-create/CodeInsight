#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int a, b,c;
    a = num/100;
    b = ((num - (num%10))/10)%10;
    c = num%10;

    if(a == 7 ||  b == 7|| c == 7)printf("Yes\n");
    else printf("No\n");

}