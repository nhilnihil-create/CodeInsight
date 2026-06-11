#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n, x, y;
	cin >> n >> x >> y;
	
	vector< vector<int> > G(n);
	for(int i = 0; i < n - 1; ++i) {
		G[i].push_back(i + 1);
		G[i + 1].push_back(i);
	}
	
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
	
	vector<int> res(n - 1, 0);
	for(int i = 0; i < n - 1; ++i) {
		vector<int> dist(n, 1e9);
		queue<int> q;
		dist[i] = 0;
		q.push(i);
	
		while( !q.empty() ) {
			int now = q.front();
			q.pop();
			
			for(auto& v : G[now]) {
				if( dist[v] > dist[now] + 1) {
					dist[v] = dist[now] + 1;
					q.push(v);
				}
			}
		}
			
		for(int j = i + 1; j < n; ++j) {
			res[dist[j] - 1]++;
		}
	}
	
	for(auto& ans : res) {
		cout << ans << endl;
	}
	
	return 0;
}
