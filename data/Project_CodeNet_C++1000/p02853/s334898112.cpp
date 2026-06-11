#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(int x) {
	int res;
	if (x == 3) {
		res = 100000;
	}
	else if (x == 2) {
		res = 200000;
	}
	else if (x == 1) {
		res = 300000;
	}
	else res = 0;
	return res;
}

int main() {
	
	int x, y; cin >> x >> y;
	if (x == 1 && y == 1) {
		cout << 1000000 << endl;
		return 0;
	}
	cout << func(x) + func(y) << endl;
	return 0;
}