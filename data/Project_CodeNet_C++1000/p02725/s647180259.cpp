#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll k,n;
    cin>>k>>n;
    ll arr[n+5]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll dis=arr[0]-arr[n-1]+k;
    for(int i=0;i<n-1;i++)
    {
        ll x=abs(arr[i+1]-arr[i]);
        dis=max(dis,x);
    }
    cout<<k-dis<<endl;
}
