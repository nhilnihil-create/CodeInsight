#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int P = 2019;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	string s;
	cin >> s;
	for (char& x : s) x -= '0';
	int a[P];
	memset(a, 0, sizeof(a));
	
	int n = s.length();
	ll ans = 0;
	int suff = 0, mul = 1;
	a[0] = 1;
	for (int i=n-1; i>=0; i--) {
		suff = (suff + s[i]*mul) % P;
		ans += a[suff];
		a[suff]++;
		mul = (mul*10) % P;
	}
	cout << ans << '\n';
}