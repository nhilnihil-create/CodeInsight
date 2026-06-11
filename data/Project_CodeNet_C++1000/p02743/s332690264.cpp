#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	if(c - a - b < 0)
		cout << "No";
	else {
		if((4 * a * b) < (c - a - b) * (c - a - b))
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}
