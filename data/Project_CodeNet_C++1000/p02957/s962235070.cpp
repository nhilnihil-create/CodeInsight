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
	int a, b; cin >> a >> b;
	int sum = a + b;
	if (sum % 2 == 0)cout << sum / 2 << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}

