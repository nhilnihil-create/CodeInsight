#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	priority_queue<int> q;
	vector<pair<int, int>> d(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		d[i] = make_pair(a, b);
	}
	sort(d.begin(), d.end());
	long long sum = 0;
	int last_i = 0;

	for (int i = m-d[0].first; i >= 0; i--) {
		if (last_i < d.size()) {
			int cura = m-i;
			int j;
			for (j = last_i; j < d.size(); j++) {
				if (d[j].first != cura) {
					last_i = j;
					break;
				}
				q.push(d[j].second);
			}
			if (j == d.size())
				last_i = j;
		}
		if (!q.empty()) {
			auto e = q.top();
			q.pop();
			sum += (long long)e;
		}
	}
	cout << sum << endl;
	return 0;
}