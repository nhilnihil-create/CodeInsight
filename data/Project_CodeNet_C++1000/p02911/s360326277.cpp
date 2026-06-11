#include "bits/stdc++.h"
using namespace std;

//42
typedef long long ll;

int main() {
	int n, k , q;
	cin >> n >> k >> q;
	vector<int> v(n);
	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		x--;
		v[x]++;
	}
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = -q + v[i] + k;
	//	cout << ans[i] << " ";
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] > 0) cout << "Yes\n";
		else cout << "No\n";
	}
}
