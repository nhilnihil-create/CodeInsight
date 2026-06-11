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
    ll a,b,i,j,n,t,m;
    vl<ll> arr;
    arr.pb(0);
    cin>>n>>m;
    ll sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
        arr.pb(sum);
    }
    ll count=0;
    for(i=0;i<n+1;i++)
    {
        if(arr[i]<=m) count++;
        else break;
    }
    cout<<count;
}