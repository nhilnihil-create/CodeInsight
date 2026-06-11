#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 300005, M = 1000000007;
ll a[N], cnt[66];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for (ll j = 0; (1LL << j) <= a[i]; j++) {
            if ((1LL << j) & a[i]) {
                cnt[j]++;
            }
        }
    }
    ll res = 0;
    for (ll i = 0; i < 66; i++) {
        ll temp = (cnt[i] * (n - cnt[i])) % M;
        res += (temp * ((1LL << i) % M)) % M;
        res %= M;
    }
    printf("%lld", res);
    return 0;
}
