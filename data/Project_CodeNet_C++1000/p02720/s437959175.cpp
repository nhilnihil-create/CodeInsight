#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll k;
	cin >> k;
	queue<ll> q;
	rep(i, 9) q.emplace(i + 1);
	int i = 0;
	while(1) {
		ll x = q.front();
		ll m = x % 10;
		q.pop();
		i++;
		if (i == k) {
			cout << x << endl;
			break;;
		}
		if (m != 0) q.emplace(x * 10 + m - 1);
		q.emplace(x * 10 + m);
		if (m != 9) q.emplace(x * 10 + m + 1);
	}
	return 0;
}
