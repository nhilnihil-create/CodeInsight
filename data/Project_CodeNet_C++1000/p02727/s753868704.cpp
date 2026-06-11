#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


typedef long long ll;


int main() {
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;

	vector<ll> p(A), q(B), r(C);
	for (int i = 0; i < A; ++i) cin >> p[i];
	for (int i = 0; i < B; ++i) cin >> q[i];
	for (int i = 0; i < C; ++i) cin >> r[i];

	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());

	p.resize(X);
	q.resize(Y);
	
	int D = p.size() + q.size() + r.size();
	vector<ll> s(D);
	for (int i = 0; i < p.size(); ++i) s[i] = p[i];
	for (int i = 0; i < q.size(); ++i) s[i + p.size()] = q[i];
	for (int i = 0; i < r.size(); ++i) s[i + p.size() + q.size()] = r[i];

	sort(s.rbegin(), s.rend());

	ll ans = accumulate(s.begin(), s.begin() + X + Y, 0LL);
	cout << ans << endl;

	return 0;
}
