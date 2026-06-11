#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int>p(a);
	for (int i = 0; i < a; i++)cin >> p.at(i);
	vector<int>q(b);
	for (int i = 0; i < b; i++)cin >> q.at(i);
	vector<int>r(c);
	for (int i = 0; i < c; i++)cin >> r.at(i);
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	sort(r.begin(), r.end());
	reverse(p.begin(), p.end());
	reverse(q.begin(), q.end());
	reverse(r.begin(), r.end());
	priority_queue<int, vector<int>, greater<int>> pq;//大きいものを残す
	for (int i = 0; i < x; i++)pq.push(p.at(i));
	for (int i = 0; i < y; i++)pq.push(q.at(i));
	for (int i = 0; i < c; i++) {
		if (pq.top() < r.at(i)) {
			pq.pop();
			pq.push(r.at(i));
		}
		else break;
	}
	ll ans = 0;
	while (pq.size() > 0) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
}