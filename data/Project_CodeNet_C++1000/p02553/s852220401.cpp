#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max({1ll*a*c, 1ll*a*d, 1ll*b*c, 1ll*b*d});
	return 0;
}