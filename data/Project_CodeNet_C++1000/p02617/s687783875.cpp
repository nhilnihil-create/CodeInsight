#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

int main(){
    int n;
    cin >> n;
    vi u(n-1), v(n-1);
    rep(i, n-1) cin >> u[i] >> v[i];
    ll sum = 0;
    rep(i, n) {
        sum += (i+1LL) * (i+2LL) / 2LL;
    }
    rep(i, n-1) {
        ll x = min(u[i], v[i]);
        ll y = max(u[i], v[i]);
        sum -= x * (n-y+1);
        // cout << x << " " << y << " " << sum << '\n';
    }
    cout << sum << '\n';
    return 0;
}