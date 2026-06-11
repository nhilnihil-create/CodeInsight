#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> a(n), x(1000001);
	rep(i,n) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i : a) {
		if (x[i] != 0) {
			x[i] = 2;
			continue;
		}
		for (int j = i; j <= 1e6; j += i) {
			x[j]++;
		}
	}
	for (int i : a) {
		if (x[i] == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}
