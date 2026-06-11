#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	rep(i,5) {
		cin >> n;
		if(n == 0) ans = i + 1;
	}
	cout << ans << endl;
	return 0;
}
