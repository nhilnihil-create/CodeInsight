#include <iostream>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    for (long long i = 0; i != n; i++)ans += (i + 1) * (n - i);
    for (int i = 0; i != n - 1; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        ans -= min(a, b) * (n - max(b, a) + 1);
    }
    printf("%lld", ans);
    return 0;
}