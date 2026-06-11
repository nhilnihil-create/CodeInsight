#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
    long long x, y, sol;
	((a*c) > (a*d)) ? x = (a*c) : x = (a*d);
	((b*c) > (b*d)) ? y = (b*c) : y = (b*d);
	(x>y) ? sol = x : sol = y;
	cout << sol << endl;
	return 0;
}
