#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];

	for (int i = 0; 1; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (p[j] == x-i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x-i << endl;
			return 0;
		}

		flag = true;
		for (int j = 0; j < n; j++) {
			if (p[j] == x+i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x+i << endl;
			return 0;
		}
	}
}