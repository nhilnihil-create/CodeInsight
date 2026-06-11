#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {
	ll n;
	cin >> n;
	fix;
	ll product = 1;
	ll cnt = 0;
	while(n != 1) {
		product *= 2;
		n /= 2;
		cnt++;
	}
	cnt = (ll)pow(2, cnt) - 1 + product;
	cout << cnt  << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}