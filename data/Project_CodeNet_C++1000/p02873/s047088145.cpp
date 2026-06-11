#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[500005];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	rep(i, n) {
		if (s[i] == '<') a[i+1] = max(a[i]+1, a[i+1]);
	}
	for (int i = n-1; i >= 0; i--)
	{
		if (s[i] == '>') a[i] = max(a[i], a[i+1]+1);
	}
	ll ans = 0;
	rep(i, n+1) ans += a[i];
	cout << ans << endl;
	return 0;
}