#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a = n/100;
    int c = n%10;
    int b = (n%100)/10;
    if (a == 7 || b == 7 || c == 7){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}