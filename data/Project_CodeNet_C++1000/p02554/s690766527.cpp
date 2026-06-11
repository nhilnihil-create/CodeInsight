#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int mod = 1e9+7;

ll powmod(ll x, ll y) {
    ll res = 1;
    for (int i=1; i<=y; i++) {
        res = res*x%mod;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    ll ans = powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N);
    ans %= mod;
    ans = (ans + mod)%mod;
    cout << ans << endl;
    return 0;
}   