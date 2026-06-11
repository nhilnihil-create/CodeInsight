#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), c(n - 1);
	rep(i, n) cin >> a[i];
	int ans = 0;
	rep(i, n) {
		int x;
		cin >> x;
		ans += x;
	}
	rep(i, n - 1) cin >> c[i];
	rep(i, n - 1) {
		if (a[i] + 1 == a[i + 1]) ans += c[a[i]-1];
	}
	cout << ans << endl;
}

