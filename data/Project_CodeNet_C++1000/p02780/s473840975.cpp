#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;

int main()
{
    ll t,i,n,k;
    ll a,c;
    long double b;
    cin>>n>>k;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll l=0,r=k-1;
    ll sum=0;
    for(i=0;i<k;i++) sum+=arr[i];
    ll mx=sum;
    for(i=1;i<n-k+1;i++)
    {
        sum-=arr[i-1];
        sum+=arr[i+k-1];
        if(mx<sum)
        {
            l=i;
            r=i+k-1;
            mx=sum;
        }
    }
    long double ans=0;
    for(i=l;i<=r;i++)
    {
        a=arr[i];
        b=(a*(a+1))/2.0;
        b/=(long double)a;
        //cout<<" "<<b<<endl;
        ans+=b;
    }
    cout<<fixed<<setprecision(8)<<ans;
}