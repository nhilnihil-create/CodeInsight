
// A - Triangle

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll MAX = 1e9;

int main() {
	ll S;
	cin >> S;

	ll x = S % MAX == 0 ? 0 : MAX - (S % MAX);
	ll y = (S + x) / MAX;

	cout << 0 << " " << 0 << " " << MAX << " " << 1 << " " << x << " " << y << endl;

	//cout << "S = " << MAX * y - 1 * x << endl; // **** debug ****

	return 0;
}