#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[2222][2222];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n;cin >> n;
	vector<P> a(n);
	REP(i, n) {
		cin >> a[i].FI;
		a[i].SE = i;
	}

	sort(ALL(a), greater<P>());
	ll ans = 0;

	REP(i, n+1){
		REP(j, n+1){
			if(i + j >= n){
				ans = max(ans, dp[i][j]);
				continue;
			}
			ll left = i;
			ll right = n - 1 - j;
			ll id = a[i+j].SE;
			ll c = a[i+j].FI;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + c * abs(id - left));
			dp[i][j+1] = max(dp[i][j+1], dp[i][j] + c * abs(id - right));
		}
	}

	cout << ans << endl;

	return 0;
}
