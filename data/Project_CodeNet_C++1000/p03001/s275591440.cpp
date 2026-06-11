#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int w, h, x, y; cin >> w >> h >> x >> y;
	int m = w * h;
	cout << fixed << setprecision(6) << m / 2.0 << " ";
	if (w % 2 == 0 && w / 2 == x && h % 2 == 0 && h / 2 == y) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}
