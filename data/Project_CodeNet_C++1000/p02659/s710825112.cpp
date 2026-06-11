#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll a;
	double b;
	ll bb;
	ll ans;
	cin >> a >> b;
	bb = (ll)(b * 100+0.01);
	ans = (ll)((a * bb)/100);

	cout << ans << endl;
	return 0;
}
