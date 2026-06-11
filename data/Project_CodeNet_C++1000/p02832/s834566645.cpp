#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	int p = 1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == p) {
			p++;
		}else {
			cnt++;
		}
	}
	if (p == 1)cout << -1;
	else 
	cout << cnt;
}
