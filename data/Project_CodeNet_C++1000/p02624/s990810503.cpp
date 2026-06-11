#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define rep(i,n)    FOR(i,0,n)
#define rep_one(i,n)    FOR(i,1,n+1)
#define rrep(i,n)   for(int i=n-1;i<=0;--i)
#define loop        while(true)
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const ll MAX = 10000000;
const ll MIN = 0;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using pl = pair<ll, ll>;
using ps = pair<int, string>;

int main() {
    ll N; sl(N);
    ll ans = 0;

    rep_one(i,N) {
        ll c = N/i;
        ans += c*i*(c+1)/2;
    }

    cout << ans << endl;

    return 0;
}
