#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll h, a, ans = 0;
	cin >> h >> a;
	ans = (h + a - 1) / a;
	cout << ans << endl;
	return 0;
}
