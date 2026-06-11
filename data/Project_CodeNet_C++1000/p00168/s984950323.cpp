#include <cstdio>
#include <cstring>
#include <cmath>

int memo[40];

int main() {
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    int n;
    for (int i = 3; i < 31; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        printf("%d\n", int(ceil(double(memo[n]) / 3650)));
    }
    return 0;
}