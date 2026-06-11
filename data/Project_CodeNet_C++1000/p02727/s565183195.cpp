#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	int p[A], q[B], r[C];
	for(int i = 0; i < A; i++) cin >> p[i];
	for(int i = 0; i < B; i++) cin >> q[i];
	for(int i = 0; i < C; i++) cin >> r[i];

	sort(p, p + A, greater<int>());
	sort(q, q + B, greater<int>());
	sort(r, r + C, greater<int>());

	vector<int> v;
	for(int i = 0; i < X; i++) v.push_back(p[i]);
	for(int i = 0; i < Y; i++) v.push_back(q[i]);
	for(int i = 0; i < C; i++) v.push_back(r[i]);
	sort(v.begin(), v.end(), greater<int>());

	ll ans = 0;
	for(int i = 0; i < X + Y; i++) ans += v[i];

	cout << ans;
	return 0;
}
