#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[509], r[509];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 1; i * i <= s; i++) {
		if (s % i != 0) continue;
		if (i * i == s) v.push_back(i);
		else {
			v.push_back(i);
			v.push_back(s / i);
		}
	}
	int ans = 1;
	for (int i = 0; i < v.size(); i++) {
		int rs = 0;
		for (int j = 0; j < n; j++) {
			r[j] = a[j] % v[i];
			rs += r[j];
		}
		sort(r, r + n);
		int mr = 0;
		for (int j = 0; j < n - rs / v[i]; j++)
			mr += r[j];
		if (mr <= k) ans = max(ans, v[i]);
	}
	cout << ans << '\n';
	return 0;
}	