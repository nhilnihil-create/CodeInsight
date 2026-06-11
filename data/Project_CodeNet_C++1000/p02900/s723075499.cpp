#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll g = __gcd(a, b), ans = 1;
    for (ll i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            ans++;
            while (g % i == 0) {
                g /= i;
            }
        }
    }
    if (g > 1) ans++;
    printf("%lld", ans);
    return 0;
}
