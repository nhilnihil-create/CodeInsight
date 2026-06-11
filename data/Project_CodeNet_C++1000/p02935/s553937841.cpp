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
    cin>>n;
    ld arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ld ans=0;
    sort(arr,arr+n);
    ans=arr[0];
    for(i=1;i<n;i++)
    {
        ans+=arr[i];
        ans/=2.0;
    }
    cout<<setprecision(8)<<fixed<<ans;
}