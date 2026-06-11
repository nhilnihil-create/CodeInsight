#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define ff first
#define ss second

vector<bool> used;
vector<vector<int>> g;

void dfs(int v) {
	used[v] = true;
  	for (int u : g[v]) {
    	if (!used[u])
          	dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
  	cin >> n >> m;
  	g.resize(n);
  	used.resize(n);
  	for (int i = 0; i < m; i++) {
    	int u, v;
      	cin >> u >> v;
      	u--, v--;
      	g[u].push_back(v);
      	g[v].push_back(u);
    }
  	int k = 0;
  	for (int i = 0; i < n; i++) {
    	if (used[i])
        	continue;
      	k++;
      	dfs(i);
    }
  	cout << k - 1;
    return 0;
}