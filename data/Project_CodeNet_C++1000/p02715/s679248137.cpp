#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll md = 1000000007;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;

ll power(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = ((res%mod) * (x%mod))%mod;
        n = (n >> 1);
        x = ((x%mod) * (x%mod))%mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, res = 0;
    cin >> n >> k;
    vl cnt(k+1, 0);
    for(int i = k; i >= 1; i--) {
    	cnt[i] = power(k/i, n);
    	for(int j = 2*i; j <= k; j += i) {
    		cnt[i] = (cnt[i] - cnt[j] + md)%md;
    	}
    	res = (res + (i*cnt[i])%md)%md;
    }
    cout << res << "\n";
    return 0;
}
