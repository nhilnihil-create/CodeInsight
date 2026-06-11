// B - 123 Triangle
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = s[i] - '1';
	vector<int> c(n);
	for (int i = 1; i < c.size(); i++) c[i] = __builtin_ctz(i) + c[i - 1];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int d = c[n - 1] - c[i] - c[n - 1 - i];
		ans ^= d ? 0 : (a[i] % 2);
	}

	if (ans != 0) {
		cout << 1 << endl;
	} else {
		bool has_one = false;
		for (int i = 0; i < a.size(); i++) if (a[i] == 1) has_one = true;
		if (has_one) {
			cout << 0 << endl;
		} else {
			for (int i = 0; i < a.size(); i++) a[i] /= 2;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				int d = c[n - 1] - c[i] - c[n - 1 - i];
				ans ^= d ? 0 : (a[i] % 2);
			}
			cout << (ans ? 2 : 0) << endl;
		}
	}

	return 0;
}
