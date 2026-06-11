#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long int li;
typedef long long ll;
typedef long double ld;

void solve()
{
	int n, s = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
        cin >> a[i];
        if ((i + 1) % 2 && a[i] % 2)
			s++;
	}
	cout << s << "\n";
}

int main()
{
	int n = 1;
	// cin >> n;
	while (n-- > 0)
		solve();
}
