#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int ans = 0;
	rep(i, str.size()/2) {
		if (str[i] != str[str.size() - i - 1]) ans++;
	}
		
	cout << ans << endl;

	return 0;
}
