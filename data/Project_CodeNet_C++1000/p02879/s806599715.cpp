#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

	int a,b;
	cin >> a >> b;

	if ((1<=a)&&(a<=9)&&(1<=b)&&(b<=9))
	{
		cout << a*b << endl;
	}
	else
	{
		cout << "-1" << endl;
	}

	return 0;
}