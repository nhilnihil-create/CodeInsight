#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n, ans=0; cin >> n;
	for (ll i=1; i<=n; i++)
		if (i % 3 != 0 && i % 5 != 0)
			ans += i;
	cout<<ans<<"\n";	
	return 0;
}
