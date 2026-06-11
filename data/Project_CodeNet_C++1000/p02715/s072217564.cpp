#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
#define all(v) v.begin()  ;v.end()
#define endl "\n";

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll n, k;
ll res = 0;
vector<int> v;

void p(int i = 1, int pre = k) {
    if (!pre) {
        int cnt = 0;
        for (int i : v)cnt = gcd(cnt, i);
        res += cnt;
        return;
    }
    // cout<<pre;
    for (int j = i; j <= n; ++j) {
        v.push_back(j);
        p(i, pre - 1);
        v.pop_back();
    }
}

ll mod = 1e9 + 7;

int main() {
    cin >> k >> n;

    ll dp[100005] = {0};
    ll ans = 0;
    for (int i = n; i > 0; --i) {
        ll now = 0;
        for (int j = i * 2; j <= n; j += i) {
            now += dp[j];
            now %= mod;

        }
        dp[i]=(binpow(n/i,k,mod)+mod-now)%mod;
        ans+=dp[i]*i;
        ans%=mod;
    }
    cout << ans  << " ";

    return 0;
}
