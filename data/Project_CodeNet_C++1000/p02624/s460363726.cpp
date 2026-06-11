#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(ll n) {
	return n*(n+1)/2;
}

int main() {
	int	n;
	ll	ans = 0;
	cin >> n;
	rep(i,n){
		ll r = n/i;
		ans += i * f(r);
	}
	cout << ans <<endl;
}