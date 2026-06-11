#include <bits/stdc++.h>

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const unsigned int M = 1e9 + 7;

int32_t main() {
	fastio;

	int h;
	cin >> h;
	int x = 1;
	while(2 * x <= h) x *= 2;
	cout << 2 * x - 1;

	return 0;
}
