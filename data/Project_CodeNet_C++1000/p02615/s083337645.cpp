#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define rep(i,n)    FOR(i,0,n)
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
    ll ans;
    ll N;
    cin >> N;
    vector<ll> seq(N);
    rep(i,N) sl(seq.at(i));

    sort(seq.begin(), seq.end(), greater<ll>());
    ans = seq.at(0); ll ptr = 2;
    for( ll i = 1; i < N && ptr < N; i++) {
        ans += seq.at(i);
        ptr++;
        if( ptr < N) {
            ans += seq.at(i);
            ptr++;
        }
    }

    cout << ans << endl;

    return 0;
}
