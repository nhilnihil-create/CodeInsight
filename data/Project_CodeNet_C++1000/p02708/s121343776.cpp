#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    fast_io
    ll i,n,k,st,en,ans=0;
    cin>>n>>k;
     for(i=k;i<=n+1;i++)
   {
       st=i*(i-1)/2;
       en=i*(2*n-i+1)/2;
       ans+=en-st+1;
       ans%=mod;

   }
    cout<<ans%mod<<endl;

    return 0;
}


