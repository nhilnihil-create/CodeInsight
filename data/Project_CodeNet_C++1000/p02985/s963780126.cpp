#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

VVI edge(114514,VI(0));
int k;
ll ans=1;

void dfs(int v, int p, int d, int f){
	ans*=max(k-min(2,d)-f,0);
	ans%=MOD;
	int m=0;
	for(int i=0;i<edge[v].size();i++){
		int to=edge[v][i];
		if(to!=p)
			dfs(to,v,d+1,i-m);
		else
			m=1;
	}
}

int main() {
	int n; cin >> n >> k;
	int a, b;
	REP(i,n-1){
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(0,-1,0,0);
	cout << ans << endl;
	return 0;
}