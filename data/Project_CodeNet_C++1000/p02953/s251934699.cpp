#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& d: a) cin >> d;
	vector<int> mn(n);
	int min = INT_MAX;
	for (int i = n-1; i > -1; --i) {
		if (a[i] < min) min = a[i];
		mn[i] = min;
	}
	for (int i = 0; i < n-1; ++i) {
		if (a[i] - mn[i+1] > 1) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}