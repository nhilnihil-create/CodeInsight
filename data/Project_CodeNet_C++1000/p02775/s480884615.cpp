#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;


void solve(){
	
	string N;
	cin >> N;

	vvl dp(1000010, vl(2, INF));
	dp[0][0] = 0;
	//dp[0][1] = 0;
	
	REV(N);
	N += '0';
	
	rep(i, N.size()) rep(j, 2){
		ll x = N[i] - '0';
		x += j;
		rep(a, 10){
			ll ni = i + 1;
			ll nj = 0;
			ll b = a - x;
			if(b < 0){
				nj = 1;
				b += 10;
			}
			chmin(dp[ni][nj], dp[i][j] + a + b);
		}
	}
	
	ll ans = min(dp[N.size()][0], dp[N.size()][1]);
	print(ans);
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}



