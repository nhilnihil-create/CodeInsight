#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> col(n + 1);
	vector<int> row(m + 1);
	vector<set<int>> rem(n + 1);
	vector<vector<int>> pos(m + 1);
	for (int i = 1;i <= k;i++) {
		int x,y;
		cin >> x >> y;
		col[x]++;
		row[y]++;
		pos[y].emplace_back(x);
		rem[x].insert(y);
	}
	int mx = *max_element(row.begin(),row.end());
	int cnt = 0;
	for (int i = 1;i <= m;i++) {
		if (row[i] != mx) {
			for (auto&x : pos[i]) {
				rem[x].erase(i);
			}
		}
		else ++cnt;
	}
	int ans = mx;
	mx = *max_element(col.begin(),col.end());
	ans += mx;
	bool flag = false;
	for (int i = 1;i <= n;i++) {
		if (col[i] == mx && (int)rem[i].size() < cnt) {
			flag = true;
			break;
		}
	}
	if (!flag) ans --;
	cout << ans;
} 