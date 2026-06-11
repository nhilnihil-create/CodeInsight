#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (ll i = sqrt(n) + 1; i >= 1; i--)
	{
		if (n % i == 0)
		{
			ans = i + n / i - 2;
			cout << ans << endl;
			break;
		}
	}
	return 0;
}