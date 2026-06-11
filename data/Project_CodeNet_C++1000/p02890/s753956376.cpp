#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int cnt[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	vector<int> c, p;
	for (int i = 1; i <= n; i++) {
		if (cnt[i])
			c.push_back(cnt[i]);
	}
	sort(c.begin(), c.end());
	p.push_back(c[0]);
	int sz = c.size();
	for (int i = 1; i < sz; i++) {
		p.push_back(p.back() + c[i]);
	}
	for (int i = 1; i <= n; i++) {
		int l = 0, r = n / i;
		while (l < r) {
			int mid = (l + r) / 2 + 1;
			int id = lower_bound(c.begin(), c.end(), mid) - c.begin();
			int t = c.size() - id;
			if (id != 0)
				t += p[id - 1] / mid;
			if (t >= i)
				l = mid;
			else
				r = mid - 1;
		}
		cout << l << "\n";
	}
	return 0;
}