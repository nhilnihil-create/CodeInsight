#include<bits/stdc++.h>
using namespace std;

int main() {
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	vector<int> p(A), q(B), r(C);
	for (int i = 0; i < A; ++i) cin >> p[i];
	for (int i = 0; i < B; ++i) cin >> q[i];
	for (int i = 0; i < C; ++i) cin >> r[i];

	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());

	priority_queue<int, vector<int>, greater<int>> Q;
	for (int i = 0; i < X; i++) Q.push(p[i]);
	for (int i = 0; i < Y; i++) Q.push(q[i]);
	
	long long ans = 0;
	for (int i = 0; i < C; i++) {
		if (r[i] > Q.top()) {
			ans += r[i];
			Q.pop();
		}
	}
	while (!Q.empty()) {
		ans += Q.top();
		Q.pop();
	}
	

	cout << ans << endl;
	return 0;
}