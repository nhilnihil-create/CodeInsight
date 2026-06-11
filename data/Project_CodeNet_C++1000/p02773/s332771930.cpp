#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	map<string, int> s;
	int maxi = 0;
	int n; cin >> n;
	rep(i, n) {
		cin >> str;
		s[str] += 1;
		maxi = max(maxi, s[str]);
	}

	for (auto& d : s) {
		if (d.second == maxi) {
			cout << d.first << endl;
		}
	}

	return 0;
}
