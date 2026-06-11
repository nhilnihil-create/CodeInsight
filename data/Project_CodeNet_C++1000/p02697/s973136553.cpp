#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	a = n / 2;
	b = a + 1;
	vector<bool> sa(n, false);
	rep(i, m) {
		cout << a+1 << ' ' << b+1;
		cout << endl;
		a--;
		b++;
		a %= n;
		b %= n;
		if (2 * abs(a - b) == n) a--;
		a %= n;
		if (sa[abs(a - b)]) b++;
		b %= n;
		sa[abs(a - b)] = true;
		sa[n - abs(a - b)] = true;
	}
	return 0;
}
