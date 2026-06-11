#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
vector<ll>G[200005];
ll ans[200005];
int main() {
	ll n, q;
	cin >> n >> q;
	
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	ll index,value;
	for (int i = 0; i < q; i++) {
		cin >>index>>value;
		index--;
		ans[index] += value;
	}

	queue<ll>que;
	vector<ll>dist(n, inf);
	vector<ll>pre(n - 1, -1);
	dist[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto id : G[x]) {
			if (dist[id] != inf) {
				continue;
			}
			dist[id] = dist[x] + 1;
			ans[id] += ans[x];
			que.push(id);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}