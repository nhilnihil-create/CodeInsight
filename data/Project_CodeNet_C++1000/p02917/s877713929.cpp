#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    n--;
    ll arr[n+5]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll sum=0;
    sum=arr[1]+arr[n];
    for(int i=1;i<=n-1;i++)
    {
        ll x=min(arr[i],arr[i+1]);
        sum+=x;
    }
    cout<<sum<<endl;



}
