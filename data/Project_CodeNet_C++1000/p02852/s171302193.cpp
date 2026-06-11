#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> g(n+1, -1);
	queue<int> q;
	int back = 0;
	for(int i = 1; i <= n; i++) {
		if (s[i] == '1') continue;
		while(i - back > m) {
			if (q.empty()) {
				cout << -1 << endl;
				return 0;
			}
			back = q.front();
			q.pop();
		}
		g[i] = back;
		q.push(i);
	}
	vector<int> ans;
	for(int current = n; current != 0; current = g[current]) {
		ans.push_back(current-g[current]);
	}
	reverse(ans.begin(), ans.end());
	for(int i: ans) {
		cout << i << ' ';
	}
	cout << endl;
}
