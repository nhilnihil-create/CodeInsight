#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll repow(ll k,ll n)
{
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans= (((ans)*k) )%mod;
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        ll k,n;
        cin>>k>>n;
        if((k*500)>=n)
        {
            cout<<"Yes";
        }
        else
            cout<<"No";
    }
}
