#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] > a[i])
			pq.push(make_pair(b[i], i));
		if (b[i] < a[i])
			return cout << "-1", 0;
	}
	long long ans = 0;
	while (!pq.empty()) {
		int i = pq.top().second;
		pq.pop();
		int reduce = b[(i - 1 + n) % n] + b[(i + 1) % n];
		if ((b[i] - a[i]) % reduce == 0) {
			ans += (b[i] - a[i]) / reduce;
			b[i] = a[i];
			continue;
		}
		if (reduce >= b[i])
			return cout << "-1", 0;
		ans += b[i] / reduce;
		b[i] %= reduce;
		if (b[i] < a[i])
			return cout << "-1", 0;
		pq.push(make_pair(b[i], i));
	}
	cout << ans;
	return 0;
}