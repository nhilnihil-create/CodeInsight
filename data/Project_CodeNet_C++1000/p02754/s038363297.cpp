#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll a, b, n;
	ll ans;
	cin >> n >> a >> b;
	ans = (n / (a + b)) * a;
	if (n % (a + b) > a)ans += a;
	else ans += n % (a + b);
	cout << ans << endl;
	return 0;
}
