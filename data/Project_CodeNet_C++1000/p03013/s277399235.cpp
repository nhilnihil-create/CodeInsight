// cities to vapori-
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+20, MOD = 1e9+7;

int gg[N];

int main(){

	fastio;
	int n,m;
	cin >> n >> m;
	fill(gg,0);
	REP(i,0,m){
		int x;
		cin >> x;
		gg[x] = 1;
	}

	vector<int> dp(n+1,1);
	for(int i = 1; i <= n; ++i){
		if(gg[i]){
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[i-1];
		if(i-2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
	}

	cout << dp[n] << endl;

	return 0;
}
