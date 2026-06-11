#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5;
ll v[N], n, m, c, p;
bool check(ll index) {
	int n1 = upper_bound(v, v + n, v[index]) - v;
	if (n - n1 < p)
		return true;
	else {
		int n2 = upper_bound(v, v + n, v[index] + m) - v;
		if (n - n2 >= p)
			return false;
		
		ll s = m * (p - 1 + n1);
		for (int j = index + 1; j <= n - p; j++)
			s += min(m, v[index] + m - v[j]);
		if (s >= m * c)
			return true;
		else
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("intt.txt", "r", stdin);
	freopen("outt.txt", "w", stdout);
#endif
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
