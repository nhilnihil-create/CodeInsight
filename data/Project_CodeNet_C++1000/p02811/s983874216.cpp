#include <bits/stdc++.h>
//#define lop(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	if (500 * n >= r) {
		cout << "Yes";

	}
	else {
		cout << "No";
	}

}