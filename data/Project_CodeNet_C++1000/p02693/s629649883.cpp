#include <stdio.h>
int main() {
    int k, a, b, flag = 0;
    scanf("%d", &k);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; i++) {
        int test = k * i;
        if (test >= a && test <= b) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("OK");
    } else {
        printf("NG");
    }
}