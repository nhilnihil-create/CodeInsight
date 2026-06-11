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
	if (1 <= a && a <= 9) {
		if (1 <= b && b <= 9) {
			cout << a * b << endl;
		}
		else cout << -1 << endl;
	}
	else cout << -1 << endl;
	return 0;
}

