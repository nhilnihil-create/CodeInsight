#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){cin>>arr[i];}
    ll c=0,ans=0;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]<=arr[i-1]){c++;}
        else if(arr[i]>arr[i-1]){c=0;}
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;

}
