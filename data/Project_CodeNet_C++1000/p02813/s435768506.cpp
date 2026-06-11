#include <bits/stdc++.h>
using namespace std;

int find_order(const vector<int>& a) {
	int n = a.size();
	int res = 1;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) c[i] = i+1;
	while (a != c) {
		next_permutation(c.begin(), c.end());
		++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	int x = find_order(a), y = find_order(b);
	cout << abs(x-y) << endl;
	return 0;
}