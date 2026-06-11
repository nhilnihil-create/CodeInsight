#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll arr[n+5]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll cur=arr[0];
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=cur)
        {
            ans++;
            cur=arr[i];
        }
    }
    cout<<ans+1<<endl;
}

