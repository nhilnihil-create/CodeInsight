#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	double b;
	ll a, ans = 0;
	cin >> a >> b;
	ll bb = (ll)(b * 100 + 0.5);
	ans = a * bb;
	ans /= 100;
	cout << ans << endl;
	return 0;
}
