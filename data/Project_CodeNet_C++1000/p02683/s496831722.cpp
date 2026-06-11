#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358
typedef long long ll; 
typedef long double ld; 

int main() {
	int n, m, x, ans = 1000000000, i, j;
	cin >> n >> m >> x;
	vector<vector<int>> set(n, vector<int>(m));
	vector<int> skills(m), cost(m);
	for(i = 0; i < n; i++) {
		cin >> cost[i];
		for(j = 0; j < m ; j++) {
			cin >> set[i][j];
			skills[j] = 0;
		}
	}
	int se = 1 << n;
	int  t = 0;
	for(int mask = 0; mask < se; mask++) {
		t = 0;
		for(i = 0; i < n; i++) {
			if((mask >> i)&1) {
				t += cost[i];
				for(j = 0; j < m; j++) {
					skills[j] += set[i][j];
				}
			}
		}
		bool ok = true; 
		for(j = 0; j < m; j++) {
			if(skills[j] < x) {
				ok = false;
			}
			skills[j] = 0;
		}
		if(ok) {
			ans = min(ans, t);
		}
	}
	if(ans == 1000000000) {
		cout << -1 << "\n";
	} else cout << ans << "\n"; 
	
	return 0;
}
