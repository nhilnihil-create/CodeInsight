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
	int n; cin >> n;
	int ans = (n + 1) / 2;
	cout << fixed << setprecision(15) << (double)ans / (double)n << endl;
	return 0;
}

