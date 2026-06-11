#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	cout << (int)(a / b) << "\n";
	cout << (int)((int)a % (int)b) << "\n";
	cout << fixed << setprecision(10)<< (a / b) << "\n";
	return 0;
}