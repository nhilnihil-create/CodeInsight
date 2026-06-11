#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    ll tot = b - a + 1;
    tot -= b / c - (a - 1) / c;
    tot -= b / d - (a - 1) / d;
    ll g = __gcd(c, d);
    c = c * d / g;
    tot += b / c - (a - 1) / c;
    printf("%lld", tot);
    return 0;
}
