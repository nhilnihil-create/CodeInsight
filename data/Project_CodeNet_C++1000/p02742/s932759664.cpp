#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	ll H, W;
	cin >> H >> W;
	ll ans;
	if (H == 1 || W == 1) ans = 1;
	else ans = (H*W+1)/2;
	cout << ans << endl;

	return 0;
}
