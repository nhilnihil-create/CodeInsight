
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
    sort(arr,arr+n);
    ll x=n/2;
    ll diff=arr[x]-arr[x-1];
    cout<<diff<<endl;


}

