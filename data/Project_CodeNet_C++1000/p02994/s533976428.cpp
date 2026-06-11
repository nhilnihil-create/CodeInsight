#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
ll v[N+10];
ll pos[N];
int main()
{
   ll n,l,mn=10000,sum=0,ans=0,k;

   cin>>n>>l;

   ll ara[n+1];

   for(ll i=1;i<=n;i++)
   {
       ara[i]=l+i-1;
       sum+=ara[i];
       k=abs(ara[i]-0);
       if(k<mn)
       {
           mn=k;
           ans=ara[i];
       }
   }

   cout<<sum-ans<<endl;


}



