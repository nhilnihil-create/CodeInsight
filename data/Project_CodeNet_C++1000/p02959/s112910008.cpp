#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100003], b[100002];
int main() {
	int n;
	cin >> n;
	rep(i, n+1) cin >> a[i];
	rep(i, n)  cin >> b[i];
	ll cnt = 0;
	rep(i, n) {
		if (a[i] >= b[i]) {
			cnt += b[i];
			a[i] -= b[i];
		} else {
			cnt += a[i];
			b[i] -= a[i];
			a[i] = 0;
			if (a[i+1] >= b[i]) {
				cnt += b[i];
				a[i+1] -= b[i];
			} else { 
				cnt += a[i+1];
				b[i] -= a[i+1];
				a[i+1] = 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}