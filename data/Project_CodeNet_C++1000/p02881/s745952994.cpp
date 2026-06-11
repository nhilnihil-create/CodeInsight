#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long dis(long n) {
    long min_d = n - 1;
    for (long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            min_d = min(min_d, (i + n / i - 2));
        }
    }
    return min_d;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", dis(n));
}