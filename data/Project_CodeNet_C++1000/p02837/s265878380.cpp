#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<vector<int>>>xy(n, vector<vector<int>>(0, vector<int>(2)));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int x, y;
			cin >> x >> y, x--;
			xy.at(i).push_back({ x,y });
		}
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << n); bit++) {
		vector<int> l(0);
		vector<int> hu(n, -1);
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				l.push_back(i);
				hu.at(i) = 1;
			}
			else hu.at(i) = 0;
		}
		bool b = false;
		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j < xy.at(l.at(i)).size(); j++) {
				int x = xy.at(l.at(i)).at(j).at(0);
				int y = xy.at(l.at(i)).at(j).at(1);
				if (hu.at(x) == y)continue;
				else {
					b = true;
					break;
				}
			}
			if (b)break;
		}
		if (b)continue;
		else ans = max(ans, (int)l.size());
	}
	cout << ans << endl;
}