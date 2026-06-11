#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	if (a < k) k -= a, a = 0;
	else a -= k, k = 0;
	if (b < k) k -= b, b = 0;
	else b -= k, k = 0;
	cout << a << " " << b << endl;
	return 0;
}