#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin>>n;
    ll arr[n+5]={0};
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    ll ans=INT_MAX;
    for(int i=1;i<=100;i++)
    {
        ll cost=0;
        for(int j=0;j<n;j++)
        {
            ll x=(arr[j]-i)*(arr[j]-i);
            cost+=x;
        }
        ans=min(ans,cost);
    }
    cout<<ans<<endl;

}
