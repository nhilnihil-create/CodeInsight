#include <bits/stdc++.h>
#define ll long long
#define M 1000000007 
#define MM 998244353
using namespace std;
 
int main()
{
	long long int n;

	cin >> n;

	long long int ans = n-1;

	for (long long int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			ans = min (ans, i + n/i -2);
		}
	}

	cout << ans;

  	return 0;
}