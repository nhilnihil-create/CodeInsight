#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll H;
	cin >> H;
	ll ans = 0;
	ll Nm = 1;
	while (H>1) {
		ans += Nm;
		H /= 2;
		Nm *= 2;
	}
	ans += Nm;
	cout << ans << endl;

	return 0;
}
