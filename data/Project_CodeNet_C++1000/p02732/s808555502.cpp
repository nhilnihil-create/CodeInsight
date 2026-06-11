#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    map<ll,ll> mp;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    ll sum=0;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        ll temp=itr->second;
        sum+=(temp*(temp-1))/2;
    }
    for(i=0;i<n;i++)
    {
        ll a=mp[arr[i]];
        ll diff=((a*(a-1))/2)-(((a-1)*(a-2))/2);
        cout<<sum-diff<<endl;
    }
}