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
	if (s == "Sunny")cout << "Cloudy" << endl;
	else if (s == "Cloudy")cout << "Rainy" << endl;
	else cout << "Sunny" << endl;
	return 0;
}

