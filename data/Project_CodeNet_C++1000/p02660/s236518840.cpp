#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int main()
{
	ll n; cin >> n;
	for(ll i = 2; i * i <= n; ++i)
		if(n % i == 0)
		{
			int cnt = 0;
			while(n % i == 0)
				n /= i, ++cnt;
			for(int j = 1; cnt >= j; ++j)
			{
				cnt -= j;
				++ans;
			}
			
		}
	if(n > 1)
		++ans;
	cout << ans << endl;
	return 0;
}