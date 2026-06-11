#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 998244353


int main() 
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n-1;i++)
    {
    	ans+=(n-1)/i;
    }
    cout<<ans<<endl;
	return 0;
}