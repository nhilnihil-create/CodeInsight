#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int ar[13][13],cost[13],check[13];

int main()
{
   //freopen("inputfile.txt","r",stdin);
   ll n,m,h;cin>>n>>m>>h;
   for(ll i=0;i<n;i++)
   {
       cin>>cost[i];
       for(ll j=0;j<m;j++)
       {
           ll k;cin>>k;
           ar[i][j] = k;

       }
   }
  ll net = 1<<n;
  ll mi = 10000000;
  for(ll i=0;i<net;i++)
  {
     ll sum=0;
     ll dup[m];
     memset(dup,0,sizeof(dup));
      for(ll j=0;j<n;j++)
      {
         ll f = 1<<j;
          if(f&i)
          {
              sum+=cost[j];
              for(ll k=0;k<m;k++)
              {
                  dup[k]+=ar[j][k];
              }

          }
      }
      bool flag = true;
      for(ll i=0;i<m;i++)
      {
          if(dup[i]<h)
          {
              flag = false;
              break;
          }
      }
      if(flag==true)mi = min(mi,sum);
  }
   if(mi == 10000000){
        cout << -1<<endl;
    }
    else{
        cout << mi<<endl;
    }
    return 0;
}
