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

	int n; cin >> n;
	int a;
	string str = "APPROVED";
	rep(i, n) {
		cin >> a;
		if (a % 2) continue;
		if (a % 5 && a % 3) str = "DENIED";
	}
	cout << str << endl;


	return 0;
}
