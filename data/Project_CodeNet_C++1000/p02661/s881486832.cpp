#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ma, mb;
    if(n % 2 == 1) {
        ma = a[n/2];
        mb = b[n/2];
        cout << mb - ma + 1 << endl;
    }
    else {
        ma = (a[n/2-1] + a[n/2]);
        mb = (b[n/2-1] + b[n/2]);
        cout << (mb - ma) + 1 << endl;
    }
}