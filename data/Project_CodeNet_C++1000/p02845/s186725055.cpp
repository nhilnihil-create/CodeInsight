#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec.at(i);
	}

	int a = 0;
	int b = 0;
	int c = 0;
	long long ans = 1;

	for (int i = 0; i < n; i++) {
		int x = 0;
		if (vec.at(i) == a) {
			a++;
			x++;
		}
		if (vec.at(i) == b) {
			if (x == 0) b++;
			x++;
		}
		if (vec.at(i) == c) {
			if (x == 0) c++;
			x++;
		}
		ans *= x;
		ans %= 1000000007;
      // cout << x << ":" << ans << endl;
	}

	cout << ans << endl;

	return 0;
}