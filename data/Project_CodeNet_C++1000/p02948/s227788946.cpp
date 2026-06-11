#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>ab(m, vector<int>(0));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > m)continue;
		a--;
		ab.at(a).push_back(b);
	}
	ll ans = 0;
	priority_queue<int, vector<int>, less<int>> pq; // 小さいものを残す
	for (int i = 0; i < m; i++) {
		for (auto a : ab.at(i))pq.push(a);
		if (pq.size() == 0)continue;
		else {
			ans += pq.top();
			pq.pop();
		}
		//cout << i << " "<<ans << endl;
	}
	cout << ans << endl;
}