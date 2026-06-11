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
	string s, t; cin >> s >> t;
	t.pop_back();
	if (s == t)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

