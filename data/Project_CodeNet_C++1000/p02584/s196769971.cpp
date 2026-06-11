#include <bits/stdc++.h>

using namespace std;

long long x, k, d;

int main() {
    scanf("%lld%lld%lld", &x, &k, &d);

    x = abs(x);

    if (x / d >= k) return 0 * printf("%lld\n", x - k * d);

    long long cnt = k - x / d;

    if (cnt % 2 == 0) printf("%lld\n", x % d);
    else printf("%lld\n", d - x % d);
}
