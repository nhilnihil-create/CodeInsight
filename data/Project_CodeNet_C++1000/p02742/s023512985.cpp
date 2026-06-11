#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long h, w;
	cin >> h >> w;
	if (h == 1 || w == 1) {
		cout << 1 << '\n';
	} else {	
		cout << (h * w + 1) / 2 << '\n';
	}
	
	return 0;
}
