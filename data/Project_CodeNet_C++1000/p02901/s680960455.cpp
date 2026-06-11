//When I wrote this only God and I knew what it is
//Now, only The_Blitz knows...
#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e3 + 2;

const ll oo = 1e9 + 2; 

int cost[N];
vector<int> pos[N];
ll dp[N][1 << 12 + 1];
int n, m;

ll go(int p, int mask){
	if(mask == (1 << n) - 1) return 0;
	if(p == m) return oo;
	ll &ans = dp[p][mask];
	if(ans != -1) return ans;
	//no tomar
	ans = oo;
	ans = min(ans, go(p+ 1, mask));
	//tomar
	int nmask = mask;
	for(int x: pos[p]){
		nmask |= (1 << x);
	}
	ans = min(ans, go(p+1, nmask) + cost[p]);
	return ans;
}

int main(){
	fastio;
	cin >> n >> m;
	for(int i = 0; i < m; ++ i){
		cin >> cost[i];
		int k; cin >> k;
		for(int j = 0; j < k; ++ j){
			int x; cin >> x;
			x --;
			pos[i].pb(x);
		}
	}
	memset(dp, -1, sizeof(dp));
	ll ret = go(0, 0);
	if(ret >= oo) cout << -1 << endl;
	else cout << ret << endl;
	return 0;
}

