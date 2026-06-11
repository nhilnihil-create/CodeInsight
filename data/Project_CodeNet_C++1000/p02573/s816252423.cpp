//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define mp make_pair
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}
int n,m;
vector<vector<int>> graph;
vector<bool> visited;
void bfs(int i, int &temp){
	if(visited[i]){
		return;
	}
	temp++;
	visited[i] = true;
	for(int node : graph[i])bfs(node,temp);
}
void testcase(){
	cin >> n >> m;
	graph.resize(n);
	visited.resize(n,false);
	set<pair<int,int>> yet;
	for(int i{0};i < m;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		if(yet.count(mp(min(u,v),max(u,v))))continue;
		yet.insert(mp(min(u,v),max(u,v)));
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int ans = -1;
	for(int i{0};i < n;i++){
		int temp = 0;
		bfs(i,temp);
		ans = max(ans,temp);
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		testcase();
	}
	return 0;
}

