#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, n;
	cin >> a >> b >> n;
	ll x = n;

	if (n >= b - 1) x = b - 1;
	ll ans = a * (x % b) / b;
	cout << ans << endl;


	return 0;
}
