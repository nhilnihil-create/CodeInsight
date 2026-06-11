#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
int main()

{
	ll x,y;

	cin>>x>>y;

	map<ll,ll>mp;

	for(ll i=0;i<y;i++)
    {
        ll a;

        cin>>a;

		mp[a]=1;
	}

	if(mp[x]==0)
    {
		cout<<x<<endl;
		return 0;
	}

	ll n=x,m=x;

	while(1)
    {
		n--,m++;

		if(mp[n]==0)
            {
		 	cout<<n<<endl;
			return 0;
		}
		if(mp[m]==0)
		{
			cout<<m<<endl;
			return 0;
		}
 	}
}
