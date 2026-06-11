#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long int li;
typedef long long ll;
typedef long double ld;

void solve()
{
	int l, r, d, k = 0;
	cin >> l >> r >> d;
	for (int i = l; i <= r; i++)
		if (i % d == 0)
			k++;
	cout << k << "\n";
}

int main()
{
	int n = 1;
	// cin >> n;
	while (n-- > 0)
		solve();
}
