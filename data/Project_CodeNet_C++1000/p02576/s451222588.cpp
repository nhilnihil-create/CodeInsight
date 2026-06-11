#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, x, t;
    cin >> n >> x >> t;
    cout << t * (n / x) + t * ((n % x) > 0);

	return 0;
}