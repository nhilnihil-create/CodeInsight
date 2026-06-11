#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w, k; cin >> h >> w >> k;
	vector<string> c(h);
	for (int i = 0; i < h; i++) {
		cin >> c[i];
	}
	int n = h + w;	
	int ans = 0;
	for (int bit = 0; bit < (1 << n); ++bit) {
		vector<bool> red(n, false);
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				red[i] = true;
			}
		}
		int cnt = 0;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (red[y] || red[h + x]) continue;
				if (c[y][x] == '#') cnt++;				
			}			
		}
		if (cnt == k) ans++;
	}
	cout << ans << endl;
    return 0;
}