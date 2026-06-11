#include<stdio.h>
 
int main() {

    int k, a, b,res=0;
    scanf("%d", &k);
    scanf("%d %d", &a, &b);

    res = a / k;
    res *= k;
    res += k;

    if(res < b || b % k == 0 || a % k == 0) {
        printf("OK");
    } else {
        printf("NG");
    }
}