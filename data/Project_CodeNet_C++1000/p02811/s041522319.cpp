#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, x;
	cin >> k >> x;
	k *= 500;

	if (k >= x) cout << "Yes" << endl;
	else cout << "No" << endl;



	return 0;
}
