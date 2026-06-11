#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	if (n % 2) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0; 
	ll div = 2;
	while (div <= n) {
		ll tmp = n / (div *= 5);

		ans += tmp;

	}
	cout << ans << endl;
	return 0;
}
