#include <iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
int ind[1001];
vector<int> v[1001];
int d[1001];
int e[1001];
bool c[1001];
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			int x; cin >> x;
			v[i].push_back(x);
		}
		d[i] = v[i][0];
		e[i] = 1;
	}
	int ans = 0;
	while (1) {
		bool f = false;
		memset(c, false, sizeof(c));
		for (int i = 1; i <= n; i++) {
			if (c[i] || c[d[i]])continue;
			if (e[i] == n)continue;
			int x = d[i];
			int y = d[d[i]];
			if (x == d[i] && y == i) {
				f = true;
				c[x] = true; c[i] = true;
				if (e[i] <= n - 2)
					d[i] = v[i][e[i]];
				if (e[x] <= n - 2)
					d[x] = v[x][e[x]];
				e[i] += 1; e[x] += 1;
			}
		}
		if (!f)break;
		ans += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (e[i] != n) {
			cout << -1 << '\n'; return 0;
		}
	}
	cout << ans << '\n';	
}