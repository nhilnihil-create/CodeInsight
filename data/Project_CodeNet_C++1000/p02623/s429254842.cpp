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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> seq_A(N+1), seq_B(M+1);
    rep_one(i,N) sl(seq_A.at(i));
    rep_one(i,M) sl(seq_B.at(i));
    // 累積和を求める
    vector<ll> cum_A(N+1,0), cum_B(M+1,0);
    rep_one(i,N) cum_A.at(i) = cum_A.at(i-1) + seq_A.at(i);
    rep_one(i,M) cum_B.at(i) = cum_B.at(i-1) + seq_B.at(i);

    // 読む本が無かったら0
    ll ans = 0;
    for(ll i = 0; i <= N; i++) {
        if( cum_A.at(i) > K) break;
        ll c = upper_bound(cum_B.begin(), cum_B.end(),
                           K - cum_A.at(i)) - cum_B.begin() - 1;
        ans = max(ans, i+c);
    }

    cout << ans << endl;

    return 0;
}
