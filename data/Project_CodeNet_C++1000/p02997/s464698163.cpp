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

ii pair_up(int a, int b) {
	return {min(a, b), max(a, b)};
}

void solve() {
	int n, k;
	cin >> n >> k;
	
	int tk = (n - 1) * (n - 2) / 2;
	if(k > tk) {
		cout << -1 << endl;
		return;
	}
	
	vvi adj(n, vi(n, 0));
	for(int i = 0; i < n - 1; i++) {
		adj[i][n - 1] = adj[n - 1][i] = 1;
	}
	
	for(int i = 0; i < n - 1 && tk > k; i++)
		for(int j = 0; j < n - 1 && tk > k; j++) {
			if(i == j) continue;
			if(adj[i][j]) continue;
			adj[i][j] = adj[j][i] = 1;
			tk--;
		}
		
	set<ii> ans;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(adj[i][j] == 1) ans.insert(pair_up(i, j));
		}
		
	cout << ans.size() << endl;
	for(ii i : ans) cout << i.ff + 1 << " " << i.ss + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}