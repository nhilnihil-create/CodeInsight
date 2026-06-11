#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int main() {
	int h, w, m; cin >> h >> w >> m;
	set<pair<int, int> > st;
	vector<pair<int,int> > hcnt(h), wcnt(w);
	for (int i = 0; i < h; ++i) hcnt[i].second = i;
	for (int i = 0; i < w; ++i) wcnt[i].second = i;
	for (int i = 0; i < m; ++i) {
		int h, w; cin >> h >> w;
		--h, --w;
		st.emplace(h, w);
		++hcnt[h].first;
		++wcnt[w].first;
	}
	sort(hcnt.begin(), hcnt.end(), greater());
	sort(wcnt.begin(), wcnt.end(), greater());
	int maxhw = hcnt[0].first + wcnt[0].first;
	for (int i = 0; i < h; ++i) {
		if (hcnt[0].first != hcnt[i].first) break;
		for (int j = 0; j < w; ++j) {
			if (wcnt[0].first != wcnt[j].first) break;
			if (st.find(pair(hcnt[i].second, wcnt[j].second)) == st.end()) {
				cout << maxhw << endl;
				return 0;
			}
		}
	}
	cout << maxhw - 1 << endl;

	return 0;
}