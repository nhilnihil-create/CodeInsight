#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    const ll mod = 998244353;
    ll n; cin >> n;
    vector<ll> d(n), cnt(n);
    inv(n,d);
    if(d[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n){
        cnt[d[i]]++;
        if(i != 0 && d[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 1; i < n; i++){
        ans *= cnt[d[i]-1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
