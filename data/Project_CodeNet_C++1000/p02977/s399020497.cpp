#include <bits/stdc++.h>

const int N = 100010;

int main(){
    int n;
    scanf("%d", &n);
    int x = n & (-n);
    if (x == n){
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 2; i + 1 <= n; i += 2){
        printf("%d %d\n", i + 1, i);
        printf("%d %d\n", i, 1);
        printf("%d %d\n", 1, i + 1 + n);
        printf("%d %d\n", i + 1 + n, i + n);
    }
    printf("%d %d\n", 2 + n, 1 + n);
    if (n % 2 == 0){
        printf("%d %d\n", n, x);
        printf("%d %d\n", n + n, (n ^ x ^ 1) + n);
    }
    return 0;
}
