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
    ll a,b,i,j,n,t,c,m;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll ans=LLONG_MAX;
    for(i=0;i<n;i++)
    {
        ll sum1=0,sum2=0;
        for(j=0;j<i;j++) sum1+=arr[j];
        for(j=i;j<n;j++) sum2+=arr[j];
        ans=min(abs(sum1-sum2),ans);
    }
    cout<<ans;
}