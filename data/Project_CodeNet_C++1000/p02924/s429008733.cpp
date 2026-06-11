#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n;
	cin >> n;
	if (n == 1)cout << 0 << endl;
	else {
		ll sum = ((n+1LL)*n / 2LL)- n;
		cout << sum << endl;
	}
	return 0;
}
