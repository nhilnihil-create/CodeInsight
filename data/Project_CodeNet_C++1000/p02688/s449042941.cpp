#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll n,k;
    cin>>n>>k;
    ll ar[n+1] = {0};
    while(k--)
    {
        ll d;
        cin>>d;
        while(d--)
        {
            ll x;
            cin>>x;
            ar[x] = 1;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(ar[i]==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;



    return 0;
}



