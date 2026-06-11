#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;
	ll dif = n % (a + b);
	ll ans = n / (a + b);
	ans *= a;
	if (dif >= a) ans += a;
	else ans += dif;

	cout << ans << endl;


	return 0;
}
