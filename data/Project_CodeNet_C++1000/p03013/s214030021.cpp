#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
vector<ll> v;
int MOD = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n+1, 0);
    v[0] = 1;
    rep(i, m) {
        int a;
        cin >> a;
        v[a] = -1;
    }
    ll ans = 0;
    if (v[1] != -1) {
        v[1] = v[0];
    }
    for (int i = 2; i <= n; i++) {
        if (v[i] != -1) {
            if (v[i - 1] != -1) {
                v[i] += v[i-1];
                v[i] %= MOD;
            }
            if (v[i -2] != -1) {
                v[i] += v[i -2];
                v[i] %= MOD;
            }
        }
    }
    cout << v[n] << endl;
    return 0;
}
