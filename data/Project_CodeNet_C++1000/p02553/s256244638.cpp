#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d; scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    printf("%lld\n", max(max(a*c, a*d), max(b*c, b*d)));
    return 0;
}
