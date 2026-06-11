#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<pair<ll,int>> v;
	ll x[N], y[N];
	rep(i,N) {
		int p, q;
		cin >> p >> q;
		x[i] = (ll)(p+q);
		y[i] = (ll)(p-q);
	}
	sort(x, x+N);
	sort(y, y+N);
	ll ans = x[N-1] - x[0];
	ans = max(ans, y[N-1] - y[0]);
	cout << ans << endl;
return 0;
}
