#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef pair<ll,ll>pll;
const  ll MAX=100000;
const  ll MOD=1e9+7;
vector<ll>sot,unsot;
ll f[MAX+100];
int main()
{

   ll n;

   cin>>n;

  double ara[n+3];

   for(ll i=0;i<n;i++)cin>>ara[i];

  double sum=0,a;

   for(ll i=0;i<n;i++)
   {
       a=ara[i];

       sum+=(1/a);

   }

   sum=1/sum;


   cout<<sum<<endl;


}


