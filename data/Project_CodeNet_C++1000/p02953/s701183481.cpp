#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	cin >> n;
	int m = 0;
	rep(i, n) {
		int h; cin >> h;
		if (h < m) {
			cout << "No" << endl;
			return 0;
		}
		m = max(m, h-1);
	}
	cout << "Yes" << endl;
	return 0;
	
	return 0;
}