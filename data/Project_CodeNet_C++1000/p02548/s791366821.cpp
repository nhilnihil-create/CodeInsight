#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll find_div(int n) {
	vector<int> divs;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			divs.push_back(i);
			divs.push_back(n/i);
		}
	}
	divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
	return (ll) divs.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 1; i < n; ++i) {
		res += find_div(n-i);
	}
	cout << res << endl;
	return 0;
}