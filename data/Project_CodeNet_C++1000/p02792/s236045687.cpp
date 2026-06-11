// In the name of God

#include <bits/stdc++.h>

using namespace std;

int d[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	auto fs = [](int x) {
		while(x >= 10) {
			x /= 10;
		}
		return x;
	};

	long long ans = 0;

	long long c = 0;

	for(int i = 1; i <= n; i++) {
		ans += d[i % 10][fs(i)];
		if(fs(i) == i % 10) c++;
		d[fs(i)][i % 10]++;
	}

	cout << ans * 2 + c;

	return 0;
}
