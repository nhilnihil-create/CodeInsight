#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	ll n;
	cin >> n;
	for(ll i = (int)sqrt(n); i >= 1; i--) {
		if(n % i == 0) {
			cout << i + n / i - 2 << "\n";
			break;
		}
	}


	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}