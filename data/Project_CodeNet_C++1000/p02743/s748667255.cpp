#include <bits/stdc++.h>

using namespace std;

// 321654987 234567891 13245
// 249999999 250000000 999999998

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	long double a,b,c;
 	long double eps = 1.0E-14;

	cin >> a >> b >> c;
	
	if(sqrt(a) + sqrt(b) + eps < sqrt(c))
	{
		cout << "Yes" << '\n';
	}
	else
	{
		cout << "No" << '\n';
	}
 
	return 0;
}