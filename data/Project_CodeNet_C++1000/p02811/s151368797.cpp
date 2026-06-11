#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int k, x;
	cin >> k >> x;

	cout << (k * 500 >= x ? "Yes" : "No") << endl;
}
	