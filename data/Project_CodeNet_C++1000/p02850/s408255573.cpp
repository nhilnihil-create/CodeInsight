#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	int N;
    cin >> N;
	vector<pii> edges(N);
	vector<vi> G(N);
	int a, b;
	rep(i,N-1) {
		cin >> a >> b;
		a--; b--;
		edges[i] = make_pair(a,b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vi coltoparent(N);
	vi visited(N,false);
	map<pii,int> C;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int K = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		int cur_color = 1;
		K = max(K,(int)G[v].size());
		for (const int& u : G[v]) {
			if (visited[u]) 
				continue;
			if (cur_color == coltoparent[v]) cur_color++;
			coltoparent[u] = C[make_pair(u,v)] = C[make_pair(v,u)] = cur_color++;
			visited[u] = true;
			q.push(u);
		}
	}
	cout << K << endl;
	rep(i,N-1) {
		cout << C[edges[i]] << endl;
	}
    return 0;
}