#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
void solve()
{
	ll l,r,d;
	cin>>l>>r>>d;
	ll c=0;
	for(ll i=l;i<=r;++i)
	{
		if(!(i%d))
			c++;
	}
	cout<<c;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
    return 0;
}