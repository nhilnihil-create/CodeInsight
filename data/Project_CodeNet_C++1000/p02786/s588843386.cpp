#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll h;//,n;
        cin>>h;
        // cout<<log2(h)<<"\n";
        ll x = (ll)(log2(h)+1);
        // cout<<x<<"\n";
        ll ans= (1<<x) - 1;
        cout<<(ll)pow(2,x)-1<<"\n";
        // cout<<ans;
    }
	return 0;
}