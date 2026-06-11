#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int x;
	cin >> x;
	int small = x % 100;
	int large = (x-small) / 100;
	int cnt_100 = 0;
	
	int p[5] = {5, 4, 3, 2, 1};
	rep(i, 5) {
		if (small <= 0) break;
		int now = min(small, small / p[i] * p[i]);
		cnt_100 += small / p[i];
		small -= now;
	}
	if (cnt_100 <= large) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}