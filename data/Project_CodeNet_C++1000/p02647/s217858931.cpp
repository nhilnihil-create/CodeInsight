#include <bits/stdc++.h>
using namespace std;

const int toomanybottlesofthiswinewecantpronounce = 100;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector < int > a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int j = 0; j < min(k, toomanybottlesofthiswinewecantpronounce); ++j) {
		vector < int > b(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			if (a[i] > i)
				++b[0];
			else
				++b[i - a[i]];
			if (i + a[i] + 1 > n)
				--b[n];
			else
				--b[i + a[i] + 1];
		}
		for (int i = 1; i < n; ++i)
			b[i] = b[i - 1] + b[i];
		b.resize(n);
		a = b;
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}
