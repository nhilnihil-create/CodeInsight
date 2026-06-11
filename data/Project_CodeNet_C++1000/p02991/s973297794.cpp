#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);
const int maxn = 100010;

int dist[maxn][3];
int n,m,s,t;
vector <int> adjlist[maxn];

int32_t main() {
	cin >> n >> m;
	for (int i =0;i<m;i++) {
		int a,b; cin >> a >> b;
		adjlist[a].push_back(b);
	}
	cin >> s >> t;
	queue <pi> q;
	memset(dist,-1,sizeof dist);
	dist[s][0] = 0;
	
	q.push(pi(s,0));
	while (!q.empty()) {
		pi cur = q.front(); q.pop();
		int x = cur.f;
		int nd = (cur.s + 1) % 3;
		//~ cout << cur.f << " " << cur.s << " " << dist[cur.f][cur.s] << "\n";
		for (auto i: adjlist[x]) {
			if (dist[i][nd] != -1) continue;
			dist[i][nd] = dist[x][cur.s] + (cur.s == 0);
			q.push(pi(i,nd));			
		}
	}
	cout << dist[t][0];
}



