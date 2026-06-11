#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> key;
	rep(i,m){
		int a,b;
		cin >> a >> b;
		int s = 0;
		rep(j,b){
			int c;
			cin >> c;
			--c;
			s |= 1<<c ; // or
		}
		key.push_back({s,a});
	}
	vector<int> dp(1<<n, inf);
	dp[0] = 0;
	rep(s,1<<n){
		rep(j,m){
			int t = s | key[j].first;
			int cost = dp[s] + key[j].second;
			dp[t] = min(dp[t],cost);
		}
	}
	int ans = dp.back();
	if(ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}