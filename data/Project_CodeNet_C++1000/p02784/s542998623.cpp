#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ll h, n;
	cin >> h >> n;
	ll m = 0;

	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;
		m += a;
	}

	if (h<=m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}