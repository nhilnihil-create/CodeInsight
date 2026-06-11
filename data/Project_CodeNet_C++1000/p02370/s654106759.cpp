#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, int> > > vvp;
typedef vector<pair<int, int> > vp;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<ll> > vvl;
typedef vector<ll> vl;
typedef vector<vector<bool> > vvb;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define yn(f) (f?"yes":"no")
#define YN(f) (f?"YES":"NO")
#define Yn(f) (f?"Yes":"No")
#define mod (1e9+7)
#define inf (1e9+7)
#define nil -1

vvi List;
vb Visit;
vi indeg;
vi out;
int V;
void bfs(int s) {
	queue<int> Q;
	Q.push(s);
	
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		Visit[now] = true;
		out.push_back(now);
		for (int i = 0; i < List[now].size(); i++)
		{
			int u = List[now][i];
			indeg[u]--;
			if (indeg[u]==0&&Visit[u]==false) {
				Q.push(List[now][i]);
			}
			
		}
	}
}
void tsort() {
	for (int i = 0; i < V; i++)indeg[i] = 0;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < List[i].size(); j++)
		{
			int u = List[i][j];
			indeg[u]++;
		}
	}
	for (int i = 0; i < V; i++)
	{
		if (indeg[i]==0&&Visit[i]==false) {
			bfs(i);
		}
	}
	for (int i = 0; i < out.size(); i++)
	{
		cout<<out[i]<<endl;
	}
}
int main() {
	int  E;
	cin >> V >> E;
	Visit.resize(V);
	rep(i, 0, V)Visit[i] = false;
	List.resize(V);
	indeg.resize(V);
	for (int i = 0; i < E; i++)
	{
		int s, t;
		cin >> s >> t;
		List[s].push_back(t);
	}
	tsort();
}
