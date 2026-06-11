#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k,q;
    cin>>n>>k>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        a[i]=k;
    }
    ll arr[q];
    for(ll i=0;i<q;i++)
    {   
        cin>>arr[i];
        a[arr[i]]++;
    }
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(a[i]-q>0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    
}