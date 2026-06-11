#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll l,r;
    cin>>l>>r;
    if(r-l>=2019)
    {
        cout<<0<<endl;
        return 0;
    }
    ll ans{2018};
    for(ll i=l;i<r;i++)
    {
        for(ll j = i+1;j<=r;j++)
        {
            ans = min(ans,((i*j)%2019));
        }
    }
    cout<<ans;
	return 0;
}