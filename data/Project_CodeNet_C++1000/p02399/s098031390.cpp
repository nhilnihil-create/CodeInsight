#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << fixed << setprecision(8) << (a / b) << ' ' << (a % b) << ' ' << ((long double)a / b) << endl;
	return 0;
}