#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, temp, ans = 1;
int main()
{
	cin >> a >> b;
	temp = __gcd(a,b);
	for (ll i = 2; i * i <= temp; i++)
	{
		if (temp % i == 0)
		{
			ans++;
			while (temp % i == 0)
			{
				temp /= i;
			}
		}
	}
	if (temp > 1)ans++;
	cout << ans; 
	return 0;
} 