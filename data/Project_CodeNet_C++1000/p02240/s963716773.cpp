#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define MAX 100000
#define NIL -1

/*

G':1-2-4 3-5
color:1 2

*/

vector<int> G[MAX];
int color[MAX];

void dfs(int u, int c) {
	stack<int> S;
	S.push(u);
	color[u] = c;
	while (!S.empty()) {
		int u = S.top(); S.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (color[v] == NIL) {
				color[v] = c;
				S.push(v);
			}
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, t; cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);
	}

	fill(color, color + MAX, NIL);
	int id = 1;
	for (int u = 0; u < n; u++) {
		if (color[u] == NIL)dfs(u, id++);
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t; cin >> s >> t;
		//cout << color[s] << " " << color[t] << endl;
		if (color[s] == color[t]) { cout << "yes" << endl; }
		else { cout << "no" << endl; }
	}

	return 0;
}