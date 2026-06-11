#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	int add = 0;
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		add += v[i];
		ans = min(ans,abs(add-(sum - add)));
	}
	cout << ans;
}

