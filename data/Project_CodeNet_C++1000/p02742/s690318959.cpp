#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll h, w;
	cin >> h >> w;
	ll p = h * w;
	if (h == 1 || w == 1)
		cout << 1;
	else if (p % 2 == 0)
		cout << p / 2;
	else
		cout << p / 2 + 1;
	return 0;
}
