#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	rep(i, q) {
		int index;
		cin >> index;
		a[index-1]++;
	}

	vector<int> p(n);
	rep(i, n) {
		int result = k - (q - a[i]);
		if (result <= 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}