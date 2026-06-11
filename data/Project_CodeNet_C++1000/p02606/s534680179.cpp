#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int L, R, d;
	cin >> L >> R >> d;
	cout << R / d - (L - 1) / d;
}
