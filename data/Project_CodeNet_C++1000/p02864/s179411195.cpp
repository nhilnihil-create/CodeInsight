#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[333][333][333];

void chmin(ll &a, ll b){
	a = min(a, b);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	REP(i, 333)REP(j, 333)REP(k, 333)dp[i][j][k] = LLINF;

	ll n, k;cin >> n >> k;
	vector<ll> v(n+1);
	REP(i, n)cin >> v[i+1];

	dp[1][0][0] = 0;
	for(int i = 1;i <= n;i++){
		REP(j, 333){
			REP(k, 333){
				if(dp[i][j][k] == LLINF)continue;
				chmin(dp[i+1][j][k+1], dp[i][j][k]);
				chmin(dp[i+1][i][k], dp[i][j][k] + max(0LL, v[i] - v[j]));
			}
		}
	}

	ll ans = LLINF;
	REP(i, n+1)REP(j, k+1)chmin(ans, dp[n+1][i][j]);

	cout << ans << endl;

	return 0;
}
