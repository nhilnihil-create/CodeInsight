#include <bits/stdc++.h>
using namespace std;

int main()
{
	long double r;
	cin >> r;
	cout << fixed << setprecision(8) << (r * r * acosl(-1)) << ' ' << (r * 2 * acosl(-1)) << endl;
	return 0;
}