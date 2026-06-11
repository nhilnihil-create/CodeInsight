#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	ll a, b, k;
	cin >> a >> b >> k;
	a = a - k;
	if(a < 0) {
		b += a;
		a = 0;
	}
	cout << max(a, 0LL) << " " << max(b, 0LL);
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}