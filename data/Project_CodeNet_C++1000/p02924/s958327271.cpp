#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	ll ans = 0;
	ans += n - 1;
	ans *= n;
	ans /= 2;
	cout << ans << endl;
	return 0;
}