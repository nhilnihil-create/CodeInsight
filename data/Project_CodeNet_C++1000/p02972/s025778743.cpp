#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
//#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795


ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}

ll N=2e5+1;

ll solve(ll t,vector<ll>& a,ll n)
{
  ll ans=0;
  for(int i=1;i<=n;i++)
    ans+=(a[i]-t)*(a[i]-t);

  return ans;

}


ll bx(ll n)
{
  ll temp=10;
  while(n)
  {
    temp=min(temp,n%10);
    n/=10;
  }
  return temp;
}

ll ax(ll n)
{
  ll temp=0;
  while(n)
  {
    temp=max(temp,n%10);
    n/=10;
  }
  return temp;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll n,x=0,cnt=0,y=0;
cin>>n;
//set<<ll>s;

vl a(n+1),store(n+1),ans(n+1);


for(int i=1;i<=n;i++)cin>>a[i];

  for(int i=n;i>=1;i--)
  {
   //ans[i]=store[i];
   store[i]%=2;
   if(store[i]!=a[i])ans[i]=1;
//if(i==3)cout<<store[3]<<"\n";
    ll j;
    if(ans[i])
      {
        cnt++;
    for( j=1;j*j<i;j++)
    {
        if(i%j==0)
        {
          if(j!=i/j)
            {
              store[j]++;
             if(j!=1) store[i/j]++;
            }
        }

  
    }
          if(j*j==i&&i!=1)store[j]++;
    
    }
   // store[i]=a[i];
  }

//cout<<store[3]<<"\n";

 /* for(int i=1;i<=n/2;i++)
  {
    store[i]%=2;
    if(a[i]!=store[i])store[i]=1;
    else store[i]=0;
    if(store[i])cnt++;
  }*/
cout<<cnt<<"\n";
  for(int i=1;i<=n;i++)if(ans[i])cout<<i<<" ";

cout<<endl;

return 0;

}