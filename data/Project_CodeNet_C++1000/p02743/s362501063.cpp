#include <bits/stdc++.h>

using namespace std;

// 321654987 234567891 13245
// 249999999 250000000 999999998

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	long long int a,b,c;
 
	cin >> a >> b >> c;
	__int128 A = a;
	__int128 B = b;
	__int128 C = c;
	__int128 val = (C - A - B);
 
	if(4LL*A*B < val*val && val > 0)
	{
		cout << "Yes" << '\n';
	}
	else
	{
		cout << "No" << '\n';
	}
 
	return 0;
}