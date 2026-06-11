#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int  a, b, c; cin >> a >> b >> c; int d = c - a - b;
	if (d > 0 && 4 * a * b < d * d) { cout << "Yes\n"; }
	else { cout << "No\n"; }
	return 0;
}