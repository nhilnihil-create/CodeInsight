#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;



int main()
{
	ll l, r;
	cin >> l >> r;
	ll d = r - l; //2018
	if (r - l >= 2018) {
		cout << 0;
		return 0;
	}
	ll ans = 10001000;
	for (ll i = l;i <= r;i++) {
		for (ll j = l;j <= r;j++) {
			if (i == j) continue;
			ans = min(ans, j * i % 2019);
			
		}
	}cout << ans;
}