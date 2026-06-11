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

void solve() {
	int n, m, s, t;
	cin >> n >> m;
	
	vector<vvii> adj(n, vvii(3));
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		
		for(int j = 0; j < 3; j++) {
			adj[u][j].pub({v, (j + 1) % 3});
		}
	}
	
	cin >> s >> t;
	s--; t--;
	
	priority_queue<pair<int, ii>> q;
	vvi dist(n, vi(3, inf));
	dist[s][0] = 0;
	q.push({-dist[s][0], {s, 0}});
	while(!q.empty()) {
		int node = q.top().ss.ff, state = q.top().ss.ss; q.pop();
		
		for(ii i : adj[node][state]) {
			if(dist[node][state] + 1 < dist[i.ff][i.ss]) {
				dist[i.ff][i.ss] = dist[node][state] + 1;
				q.push({-dist[i.ff][i.ss], {i.ff, i.ss}});
			}
		}
	}
	
	if(dist[t][0] == inf) cout << -1 << endl;
	else cout << dist[t][0] / 3 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}