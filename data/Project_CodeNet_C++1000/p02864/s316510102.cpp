#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

#define INF 1e15

using namespace std;

ll dp[301][302][302];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, k; cin>>n>>k;
	unordered_map<int, ll> Map, RMap;
	set<ll> Set; Set.ins(0);
	vll h(n);
	rep(i, n){
		cin>>h[i];
		Set.ins(h[i]);
	}
	int idx=0;
	for(auto e:Set){
		Map[idx] = e;
		RMap[e] = idx;
		idx++;
	}

	rep(i, n+1)rep(j, k+2)rep(l, Map.size()){
		dp[i][j][l] = INF;
	}
	dp[0][0][0] = 0ll;
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			for(int l=0; l<Map.size(); l++){
				dp[i+1][j][RMap[h[i]]] = min(dp[i+1][j][RMap[h[i]]], dp[i][j][l]+max(0ll, h[i]-Map[l]));
				dp[i+1][j+1][l] = min(dp[i+1][j+1][l], dp[i][j][l]);
			}
		}
	}

	ll ans = INF;
	for(int l=0; l<Map.size(); l++){
		ans = min(ans, dp[n][k][l]);
	}
	cout << ans << "\n";
	return 0;
}