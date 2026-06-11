#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
using namespace std;
const int mod = 313, INF = 1000000000;
ll cost[10005];
bool vis[10005];
vector<int> key;
int main() {
	int n, m,able=0;
	cin >> n >> m;
	for (int i = 0; i <= 10000; i++)cost[i] = INF;
	for (int i = 0; i < m; i++) {
		int b, p = 0;
		ll a;
		cin >> a >> b;
		for (int i = 0; i < b; i++) {
			int k;
			cin >> k;
			p |= (1 << (k - 1));
		}
		able |= p;
		key.push_back(p);
		vis[p] = 1;
		cost[p] = min(a,cost[p]);
	}
	if (able != (1 << n) - 1) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < key.size();i++) {
		for (int j = 0; j < key.size();j++) {
			int z= key[i] | key[j];
			if (!vis[z]) {
				key.push_back(z);
				vis[z] = 1;
			}
			cost[z] =min( cost[key[i]] + cost[key[j]], cost[z]);
		}
	}
	cout << cost[(1 << n) - 1];
	return 0;
}