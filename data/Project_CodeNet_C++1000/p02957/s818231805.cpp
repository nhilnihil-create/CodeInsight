#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll A, B;
	cin >> A >> B;
	ll ans = A + B;
	if((ans % 2))
		cout << "IMPOSSIBLE";
	else
		cout << ans / 2;
	return 0;
}