#include "bits/stdc++.h"

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

//#define int long long
#define ll long long

ll INF = (1LL << 60);
int mod = 998244353;
using P = pair<ll, ll>;
double PI = 3.1415926535;
signed main() {
	string s; cin >> s;
	int a = s.back() - '0';
	if (a == 2 || a == 4 || a == 5 || a == 7 || a == 9) {
		cout << "hon" << endl;
	}
	else if (a == 3) {
		cout << "bon" << endl;
	}
	else cout << "pon" << endl;
	return 0;
}

