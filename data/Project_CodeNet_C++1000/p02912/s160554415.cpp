#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	map<int,int> a;

	int in1;
	for (int i = 0; i < n; i++) {
		cin >> in1;
		a[in1]++;
	}

	for (int i = 0; i < m; i++) {
		auto ma=prev(a.end());
		a[ma->first / 2]++;
		ma->second--;
		if (ma->second == 0) { a.erase(ma); }
	}

	long long res = 0;

	for (auto itr = a.begin(); itr != a.end(); itr++) {
		res += (long long)itr->first*itr->second;
	}

	cout << res << endl;

	return 0;
}