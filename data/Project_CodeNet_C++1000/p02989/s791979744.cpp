#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t;
    string s;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    b=n/2;
    a=b-1;
    ll ans=arr[b]-arr[a];
    cout<<ans;
}