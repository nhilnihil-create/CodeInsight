#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w,k;
	cin>>h>>w>>k;
	vector<string> s(h);
	for (auto& str : s) cin >> str;
		int ans = 0;
	for (int bsr = 0; bsr < (1<<h); ++bsr) {
		for (int bsc = 0; bsc < (1<<w); ++bsc) {
			auto done = s;
			int cnt = 0;
			for (int i = 0; i < h; ++i) if (bsr&(1<<i)) {
				for (int j = 0; j < w; ++j) {
					done[i][j] = '*';
				}
			}
			for (int i = 0; i < w; ++i) if (bsc&(1<<i)) {
				for (int j = 0; j < h; ++j) {
					done[j][i] = '*';
				}
			}
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					if (done[i][j] == '#')
						++cnt;
				}
			}
			// cout << bsr << " " << bsc << endl;
			// for (auto s : done) {
			// 	cout << s << endl;
			// }
			// cout << "$$$" << endl;
			if (cnt==k) {
				++ans;
			}
		}
	}
	cout << ans << endl;
}