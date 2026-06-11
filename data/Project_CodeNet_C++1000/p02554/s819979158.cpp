#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

const int mod = 1e9 + 7;

ll powmod(ll x, ll y) {
    ll ans = 1;
    rep(i, y){
        ans = (ans * x) % mod;
    }
    ans %= mod;
    return ans;
}

int main() {
    int n;
    cin >> n;
    ll ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    /*if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        cout << 2 << endl;
        return 0;
    }
    ll ans = 0;
    int now_n = n - 2;
    ans = now_n * 9;
    ans *= fact(n);
    cout << ans << endl;*/
    return 0;
}