#include<bits/stdc++.h>

using namespace std;

long long x, k, d;
int main()
{
	cin >> x >> k >> d;
	if(x == 0)
	{
		if(k % 2 == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << d << endl;
		}
		return 0;
	}
	if(x < 0)
	{
		x = -x;
	}
	if(x < d)
	{
		if(k % 2 == 0)
		{
			cout << x << endl;
		}
		else
		{
			cout << d - x << endl;
		}
		return 0;
	}
	long long y = x / d;
	if(y < k)
	{
		long long now = x % d;
		if((k - y) % 2 == 0)
		{
			cout << now << endl;
		}
		else
		{
			cout << d - now << endl;
		}
	}
	else
	{
		cout << x - k * d << endl;
	}
	return 0;
}

















