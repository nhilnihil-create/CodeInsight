#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b,k;
	cin >> a >> b >> k;
	
	ll aa = max(a - k, (ll)0);
	ll kk = max(k - a, (ll)0);
	ll bb = max(b - kk, (ll)0);
	
	cout << aa << " " << bb <<endl;


	return 0;
}
