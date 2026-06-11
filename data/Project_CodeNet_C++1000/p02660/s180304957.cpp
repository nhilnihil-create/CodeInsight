#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

bool is_prime(ll a) {
	if (a == 1) return false;

	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;

	}
	return true;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a;
	ll n; cin >> n;
	int cnt = 0;
	ll b = n;

	for (ll i = 2; i*i  <= n; i++) {
		int c = 0;
		while (true) {
			if (n % i) break;
			c++;
			n /= i;
		}
		a.emplace_back(c);
	}

	

	for (auto d : a) {
		int i = 1;
		while (true) {
			if (d - i < 0) break;
			d -= i++;
			cnt += 1;
		}
	}
	if (n != 1) cnt++;
	cout << cnt << endl;



	return 0;
}
