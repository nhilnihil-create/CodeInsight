#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

bool sort_1(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int main() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> y(n);
	rep(i, n) cin >> y.at(i).first >> y.at(i).second;
	int ans = 0;
	sort(y.begin(), y.end(), sort_1);
	priority_queue<int> o;
	int j = 0;
	rep(i, m) {
		while (1) {
			if (j >= y.size()) {
				for(int k=i;k<m;k++) if (!(o.empty())) { ans+= o.top(); o.pop(); }
				cout << ans << endl; return 0;
			}
			if (!(y.at(j).first < i + 2)) break;
			else { o.push(y.at(j).second); j++; }
		}
		if (!(o.empty())) { ans+= o.top(); o.pop(); }
	}
	cout << ans << endl;
}