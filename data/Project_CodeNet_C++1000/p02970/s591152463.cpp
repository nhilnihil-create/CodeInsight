#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple


signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a;
	int b;
	cin >> a >> b;
	b = 2 * b + 1;
	cout << (a + b - 1) / b << endl;

	return 0;
}
