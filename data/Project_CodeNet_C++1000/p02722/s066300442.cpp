#include <bits/stdc++.h>
using namespace std;

set < long long > divs (long long x) {
	set < long long > res;
	if (x != 1)
		res.insert(x);
	for (long long i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			res.insert(i);
			res.insert(x / i);
		}
	}
	return res;
}

signed main () {
	long long n;
	cin >> n;
	set < long long > a = divs(n);
	set < long long > ans = divs(n - 1);
	for (long long x: a) {
		long long t = n;
		while (t % x == 0) 
			t /= x;
		if (t % x == 1)
			ans.insert(x);
	}
	cout << int(ans.size()) << '\n';
}
