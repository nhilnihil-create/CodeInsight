#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	
	int a, b;
	cin >> a >> b;
	ll p = (ll)a * (ll)b;
	int x = __gcd(a, b);
	cout << p / x << "\n";




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}