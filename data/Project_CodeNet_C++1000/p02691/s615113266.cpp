#include "bits/stdc++.h"

using namespace std;
using ll = long long;

map <ll, ll> mp1;
map <ll, ll> mp2;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll Ai; scanf("%lld", &Ai);
        mp1[i + Ai]++, mp2[i - Ai]++;
    }

    ll ans = 0;
    for (auto xx : mp1) {
        ans += (xx.second * mp2[xx.first]);
    }

    // ans /= 2;
    printf("%lld\n", ans);
}