#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int a, b, c, k, ans = 0;
	cin >> a >> b >> c >> k;
	if (a >= k)
	{
		ans += k;
	}
	else
	{
		ans += a;
		k -= a;
		if (b < k)
		{
			k -= b;
			ans -= k;
		}
	}
	cout << ans;
}