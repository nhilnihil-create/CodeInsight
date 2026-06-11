#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    long long full = n / (a + b);
    long long res = full * a + min(a, n - full * (a + b));
    printf("%lld\n", res);
}
