#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int x,y;
/*
a+2b=x
2a+b=y
a=(-x+2y)/3
b=(2x-y)/3
*/
ll f[1010101], invf[1010101];
ll inv(ll x) {
    ll res = 1;
    ll k = inf - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % inf;
        y = (y * y) % inf;
        k >>= 1;
    }
    return res;
}

void init() {
    f[0] = 1;
    rep(i, 1, 1010101) f[i] = (f[i - 1] * i) % inf;
    rep(i, 0, 1010101) invf[i] = inv(f[i]);
}

ll comb(int n, int k) {
    ll a = f[n];
    ll b = invf[n-k];
    ll c = invf[k];
    ll bc = (b * c) % inf;
    return (a * bc) % inf;
}

int main(){cout<<fixed<<setprecision(10);
           cin >> x >> y;
           ll a=( - x + 2 * y ),b=( 2 * x - y );
           if( a % 3 != 0 || b % 3 != 0 || a < 0 || b < 0 ) {
            cout << 0 << endl;
             return 0;
           }
           a/=3;b/=3;
           init();
           cout << comb (a+b , a ) << endl;
           //cout << a << " " << b << endl;
}