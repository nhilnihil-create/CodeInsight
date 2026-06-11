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
    ll a,b,i,j,n,t,d,k;
    ll l,r;
    cin>>l>>r;
    if(r-l>=2019)
    {
        cout<<"0";
        return 0;
    }
    ll ans=INT_MAX;
    for(i=l;i<=r;i++) for(j=l;j<=r;j++)
    {
        a=i*j;
        if(i<j)
            ans=min(ans,a%2019);
    }
    cout<<ans;
}