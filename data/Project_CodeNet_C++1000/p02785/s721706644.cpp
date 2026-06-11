#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll n,m,a=0,i,j;
    cin>>n>>m;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    if(m>=n) cout<<"0";
    else
    {
        j=n-m;
        for(i=0;i<j;i++) a+=arr[i];
        cout<<a;
    }
}