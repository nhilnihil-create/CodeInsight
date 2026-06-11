#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, b, n) for (int i = b; i < (b)+(n); i++)
using namespace std;
using ll = long long;

int main() {
	int n;
	ll m = 1000;
	cin >> n;
	vector<int> a(n + 5, 0);
	rep(i, n) cin >> a[i];
	int i = 0, mi = 200;
	while (i < n - 1) {
		mi = min(mi, a[i]);
		if (a[i] <= a[i + 1] && a[i + 1] > a[i + 2]) {
			m += (a[i + 1] - mi)*(ll)(m / mi);
			mi = 200;
		}
		i++;
	}
	cout << m << endl;
}