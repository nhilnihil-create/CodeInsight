#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5;
ll v[N], n, m, c, p;
bool check(int i) {
	int n1 = upper_bound(v, v + n, v[i]) - v;
	if (n - n1 < p)
		return true;
	else {
		int n2 = upper_bound(v, v + n, v[i] + m) - v;
		if (n - n2 >= p)
			return false;

		ll s = m * (p - 1 + n1);
		for (int j = n1; j <= n - p; j++)
			s += min(m, v[i] + m - v[j]);
		if (s >= m * c)
			return true;
		else
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> c >> p;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v + n);
	int ans, s = 0, e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (check(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << n - ans;
	return 0;
}
