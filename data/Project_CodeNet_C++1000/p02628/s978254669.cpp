
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
int main()
{
     ll n,m;

     cin>>n>>m;

     ll ara[n+1];
     for(ll i=0;i<n;i++)
     {
         cin>>ara[i];
     }

     ll sum=0;
     
     sort(ara,ara+n);

     for(ll i=0;i<m;i++)
     {
         sum+=ara[i];
     }

     cout<<sum<<endl;


}

