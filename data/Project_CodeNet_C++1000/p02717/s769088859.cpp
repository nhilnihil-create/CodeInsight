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

	int a, b, c;
	cin >> a >> b >> c;
	swap(a, b);
	swap(a, c);
	cout << a << " " << b << " " << c << "\n";


}