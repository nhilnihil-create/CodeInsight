 // In the name of GOD
 
#include <bits/stdc++.h>
#define ll long long
#define pp pair <int, int>
using namespace std;
const int N = 1e5 + 10, MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1.0/a[i];
	}
	// cout << ans;
	ans = 1.0/ans;
	cout << setprecision(12) << ans;
}
int main () {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve();
    }
}                                  