#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n, odd;
	cin >> n;
	if (n % 2 == 0)
		odd = n/2;
	else
		odd = (n/2)+1;
	double x = (double)odd / n;
	cout << setprecision(10) << fixed << x << endl;
	return 0;
}