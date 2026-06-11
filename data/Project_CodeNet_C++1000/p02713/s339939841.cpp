#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a, int b)
{
	if (a==0) return b;
	if (b==0) return a;
	if (a==b) return a;
	if (a>b) return gcd(b, a%b);
	return gcd(a, b%a);
}

int main()
{
	int ans = 0;
	int k;
	cin >> k;
	for(int a=1; a <= k; a++)
	{
		for(int b=1; b <= k; b++)
		{
			for(int c=1; c <= k; c++)
			{
				int t = gcd(gcd(a, b), c);
				ans += t;
			}
		}
	}
	cout << ans << endl;
	return 0;
}