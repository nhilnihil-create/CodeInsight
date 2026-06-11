#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<pair<int, int>> process;
	long long ans = a[n - 1];
	long long tmp = a[0];
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > 0) {
			process.emplace_back(tmp, a[i]);
			tmp -= a[i];
		} else {
			process.emplace_back(ans, a[i]);
			ans -= a[i];
		}
	}
	process.emplace_back(ans, tmp);

	cout << ans - tmp << endl;
	for (int i = 0; i < process.size(); i++) {
		cout << process[i].first << " " << process[i].second << endl;
	}

	return 0;
}