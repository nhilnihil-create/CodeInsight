#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
ll v[N+10];
int main()
{
     ll n;

     cin>>n;

     ll ara[n+1];

     for(ll i=0;i<n;i++)
     {
         cin>>ara[i];
     }
     sort(ara,ara+n);

     ll cnt=0;

     for(ll i=0;i<n;i++)
     {
         if(i>0&&ara[i-1]==ara[i])
         {
             v[ara[i]]++;
             continue;
         }

         for(ll j=ara[i];j<=N;j+=ara[i])
         {
             v[j]++;
         }
     }



     for(ll i=0;i<n;i++)
     {
         if(v[ara[i]]==1)cnt++;
     }

     cout<<cnt<<endl;

}

