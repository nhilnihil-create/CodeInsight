#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b + c >= 22) cout << "bust" << endl;
	else cout << "win" << endl;

	return 0;
}
