#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
const int MOD = 1000000007;

ll modpow(ll x, ll n) {
    x = x%MOD;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%MOD;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%MOD, n/2)%MOD;  //nが偶数ならnが半分になる
}

ll com(ll n, ll k) {
    ll x = 1;
    for(int i=n-k+1; i<=n; i++) {
        x = x*i%MOD;
    }

    ll y = 1;
    for(int i=1; i<=k; i++) {
        y = y*i%MOD;
    }
    y = modpow(y, MOD-2);

    return x*y%MOD;
}

int main() {
    
    ll n,a,b;
    cin >> n >> a >> b;

    ll all=modpow(2,n)-1;
    ll muri=com(n,a)+com(n,b);

    ll ans=all-muri;
    while(ans<0) {
        ans+=MOD;
    }

    cout << ans << endl;

}