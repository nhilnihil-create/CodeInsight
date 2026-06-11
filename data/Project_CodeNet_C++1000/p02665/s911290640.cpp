#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define x first
#define y second
using namespace std;
using ll  = long long;
#define int ll
 
const int N 	= 1e6;
const int INF 	= 0x3f3f3f3f3f3f3f3fLL;
int n;
int a[N];
int b[N];
 
signed main() {
#ifdef LC
    assert(freopen("input.txt", "r", stdin));
#endif
    ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 0) {
		if (a[0] != 1) {
			cout << "-1\n";
		} else {
			cout << "1\n";
		}
		return 0;
	}
	if (a[0]) {
		cout << "-1\n";
		return 0;
	}
	b[0] = 1;
	for (int i = 1; i <= n; ++i) {
		b[i] = min(INF, 2 * b[i - 1] - a[i]);
		if (b[i] < 0) {
			cout << "-1\n";
			return 0;
		}
	}
	b[n] = 0;
	for (int i = n; i > 0; --i) {
		b[i - 1] = min(b[i - 1], a[i] + b[i]);
	}
	int answer = 0;
	for (int i = 0; i <= n; ++i) {
		answer += a[i] + b[i];
	}
	cout << answer << "\n";
    return 0;
}
