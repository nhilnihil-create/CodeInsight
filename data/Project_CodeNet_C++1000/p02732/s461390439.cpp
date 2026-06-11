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
const int INF = 1e9;
//int m[3000];

ll memo[200005];

ll comb(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	vector<ll>b(n);
	rep(i, n) {
		ll buf;
		cin >> buf;
		buf--;
		a[i] = buf;
		b[buf]++;
	}
	
	ll sum(0);
	rep(i, n) {
		sum += comb(b[i]);
	}
	//cout << sum;
	rep(i, n) {
		ll ans = sum;
		ans -= comb(b[a[i]]);
		ans += comb(b[a[i]] - 1);
		cout << ans << endl;
	}
	return 0;
}