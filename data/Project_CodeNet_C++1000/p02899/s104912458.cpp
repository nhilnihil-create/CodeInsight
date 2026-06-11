#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll arr[n+5]={0};
    ll pos[n+5]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<pos[i]<<" ";
    }
    cout<<endl;
}
