#include<bits/stdc++.h>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;
 
int n;
int x[50], y[50];
 
signed main() {
	int i, j, k;
	
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];
	
	int ans = n;
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			int p = x[i] - x[j];
			int q = y[i] - y[j];
			if (p < 0 || (p == 0 && q < 0)) continue;
			
			int usedCnt = 0;
			bool used[50] = {false};
			int loopCnt = 0;
			while (usedCnt < n) {
				int id = -1;
				rep(k, n) {
					if (used[k]) continue;
					if (id == -1 || x[id] > x[k] || (x[id] == x[k] && y[id] > y[k])) {
						id = k;
					}
				}
				if (id == -1) { cout << "error" << endl; return 0; }
				
				used[id] = true; usedCnt++;
				while (true) {
					rep(k, n) {
						if (used[k]) continue;
						if (x[k] == x[id] + p && y[k] == y[id] + q) {
							break;
						}
					}
					if (k == n) break;
					used[k] = true; usedCnt++;
					id = k;
				}
				loopCnt++;
			}
			ans = min(ans, loopCnt);
		}
	}
	cout << ans << endl;
	return 0;
}