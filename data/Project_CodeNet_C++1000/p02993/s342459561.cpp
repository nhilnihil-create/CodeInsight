#include "bits/stdc++.h"

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

//#define int long long
#define ll long long

ll INF = (1LL << 60);
int mod = 998244353;
using P = pair<ll, ll>;

signed main() {
	string s; cin >> s;
	if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
		cout << "Bad" << endl;
	}
	else cout << "Good" << endl;
	return 0;
}

