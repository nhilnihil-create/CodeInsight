#include <bits/stdc++.h>
#include <chrono>
#define fr first
#define sc second
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll md = 1000000007;

ll ad(ll a, ll b) {
    return (a%md + b%md + md) % md;
}

ll ml(ll a, ll b) {
    return ( (a%md) * (b%md) ) % md;
}

ll pw(ll x, ll n) {
    ll res = 1;
    x %= md;
    while (n) {
        if (n & 1)  res = (res*x)%md;
        x = (x*x)%md;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, k, dn = 0, cur, ans = 0, cnt = 0;
    unordered_map<int, int> m;
    cin >> n >> k;
    vl a(10000);
    for(int i = 1; i <= k; i = cur + 1) {
        cur = k/(k/i);
        m[cur] = dn;
        a[dn++] = cur;
    }
    vl dp(dn, 0);
    for(int i = dn - 1; i >= 0; i--) {
        dp[i] = pw(k/a[i], n);
        for(int j = 2*a[i]; j <= k; j = (cur/a[i] + 1)*a[i]) {
            cur = k / (k / j);
            dp[i] -= ((cur-j)/a[i] + 1) * dp[m[cur]];
            dp[i] %= md;
            if(dp[i] < 0) dp[i] += md;
        }
        if(i == 0) {
        	ans += ((a[i]*(a[i]+1))/2) * dp[i];
        } else {
        	ans += ((a[i]*(a[i]+1))/2 - (a[i-1]*(a[i-1]+1))/2) * dp[i];
        }
        ans %= md;
    }
    cout << ans << "\n";
    return 0;
}