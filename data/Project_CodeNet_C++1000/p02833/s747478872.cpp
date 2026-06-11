#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

const ll mod = 1000000007;
ll a = 1e18;

int main() {
	ll n;
	cin >> n;
	if (n % 2 != 0) {
		cout << 0;
		return 0;
	}
	ll b = 5;
	ll ans(0);
	while (1) {
		ll cnt = n / b;
		cnt /= 2;
		ans += cnt;
		ll t = b;
		b *= 5;
		if (b > n)break;
		if (b / 5 != t)break;
	}

	cout << ans;
	return 0;
}