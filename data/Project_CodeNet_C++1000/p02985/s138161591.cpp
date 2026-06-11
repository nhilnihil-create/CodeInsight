#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int n, k;
ll ans;
vvi adj;

void dfs(int u, int p) {
	int avail = k - 2;
	if(p == -1) avail++;
	for(int i : adj[u]) {
		if(i == p) continue;
		ans *= avail;
		ans %= P;
		avail--;
		dfs(i, u);
	}
}

void solve() {
	cin >> n >> k;
	
	adj.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		adj[a].pub(b);
		adj[b].pub(a);
	}
	
	ans = k;
	dfs(0, -1);
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}