#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	vector<int> v(n);
	rep(i, n) v[i] = i + 1;
	int a, b, cnt = 0;
	do {
		bool oka = true;
		bool okb = true;
		rep(i, n) {
			if (v[i] != p[i]) oka = false;
			if (v[i] != q[i]) okb = false;
		}
		if (oka) a = cnt;
		if (okb) b = cnt;
		cnt++;
	} while (next_permutation(v.begin(), v.end()));
	cout << abs(a - b) << endl;
	return 0;
}