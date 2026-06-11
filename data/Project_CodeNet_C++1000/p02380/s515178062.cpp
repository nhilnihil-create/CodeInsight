#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, C;
	cin >> a >> b >> C;
	cout << fixed << setprecision(6);
	cout << a * b * sin((double)C / 180 * acos(-1)) / 2.0 << endl;
	cout << a + b + sqrt(a * a + b * b - a * b * 2 * cos((double)C / 180 * acos(-1))) << endl;
	cout << b * sin((double)C / 180 * acos(-1)) << endl;
	return 0;
}
