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
ll Max = 10 + 1e12;
int N = 5 + 1e5;


int main()
{
	int l, r; cin >> l >> r;
	ll ans = Max;
	if (r / 2019 - l / 2019 > 0) {
		cout << 0;
	}
	else {
		for (ll i = l;i <= r;i++) {
			for (ll j = l;j <= r;j++) {
				if (i == j) continue;
				ans = min(ans, (i * j) % 2019);
			}
		}
		cout << ans;
	}
}