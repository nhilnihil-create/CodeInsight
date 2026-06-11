#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int n; cin >> n;
	int a[200000];
	rep(i,n) cin >> a[i];
	lint ans = 9999999999999999;
	lint l,r;
	l = r = 0;
	rep(i,n) r += a[i];
	rep(i,n) {
		l += a[i];
		r -= a[i];
		ans = min(ans, abs(r-l));
	}
	cout << ans << endl;
}