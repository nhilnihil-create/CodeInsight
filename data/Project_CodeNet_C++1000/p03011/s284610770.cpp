// ABC_129_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int p, q, r;
	cin >> p >> q >> r;

	int ans = min(p+q, min(q+r, r+p));

	cout << ans << "\n";

	return 0;
}