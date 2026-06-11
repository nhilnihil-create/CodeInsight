#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;


int main() {
	FASTIO
	int h, w;
	cin >> h >> w;
	int m;
	cin >> m;
	vector<int> horizontal(w + 1), vertical(h + 1);
	unordered_map<int, unordered_map<int, bool>> mp;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a][b] = 1;
		horizontal[b]++;
		vertical[a]++;
	}
	int mx = 0;
	vector<int> u, v;
	mx = *max_element(vertical.begin(), vertical.end());
	for (int i = 0; i <= h; i++) {
		if (mx == vertical[i]) {
			u.push_back(i);
		}
	}
	mx = *max_element(horizontal.begin(), horizontal.end());
	for (int i = 0; i <= w; i++) {
		if (mx == horizontal[i]) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < u.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			mx = max(mx, horizontal[v[j]] + vertical[u[i]] - mp[u[i]][v[j]]);
			if (!mp[u[i]][v[j]])return cout << mx << endl, 0;
		}
	}
	cout << mx << endl;
}

