#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long int li;
typedef long long ll;
typedef long double ld;

int main()
{
    ll r, g, b, k;
    cin >> r >> g >> b >> k;
    // b > g > r
	// 7 2 5
	// 3
    ll s = 0;
    while (g <= r)
	{
        g *= 2;
        s++;
	}
	while (b <= g)
	{
		b *= 2;
		s++;
	}
	if (s <= k)
		cout << "Yes\n";
	else
		cout << "No\n";
}
