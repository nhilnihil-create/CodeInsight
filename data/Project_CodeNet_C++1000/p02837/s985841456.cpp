#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
	int accumIndex = 0;
	vector<int> startIndex(n);
	vector<int> endIndex(n);
	vector<pair<int, int>> c;
	for (int i = 0; i < n; i++) {
		startIndex[i] = accumIndex;
		int a; cin >> a;
		for (int j = accumIndex; j < accumIndex + a; j++) {
			int x, y; cin >> x >> y;
			--x;
			c.push_back({ x,y });
		}
		accumIndex += a;
		endIndex[i] = accumIndex;
	}	
	int ans = 0;
	for (int bit = 0; bit < (1 << n); ++bit) {
		int truePersonCnt = 0;
		vector<int> truePerson(n, false);
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				truePerson[i] = true;
				truePersonCnt++;
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (!truePerson[i]) continue;
			for (int j = startIndex[i]; j < endIndex[i]; j++) {
				int x = c[j].first;
				int y = c[j].second;
				if (y == 1) {
					if (!truePerson[x]) ok = false;
				}
				else { // y == 0
					if (truePerson[x]) ok = false;
				}
			}
		}
		if(ok) ans = max(ans, truePersonCnt);
	}
	cout << ans << endl;
	return 0;
}