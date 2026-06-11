#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
#define MOD 998244353
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}
 
ll pow(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;
}
 
 
 
/*const int N=200000;
 
ll fac[N+1];
ll inv[N+1];
ll p=998244353;
 
ll c(ll a, ll b,ll m)
{
  if(a<b)return 0;
  return (fac[a]*inv[b]%m)*(inv[a-b])%m;
}
 
*/


ll coeff[3005];
  

int main()
{ fast

ll n,s;cin>>n>>s;

coeff[0]=1;

ll p=998244353;

vl a(n+1);

for(int i=1;i<=n;i++)cin>>a[i];

for(int i=1;i<=n;i++)
{
  vl temp(3001);
  
  for(int j=0;j<=3000;j++)temp[j]=coeff[j]*2%p;

   for(int j=0;j<=3000;j++)
   {
    if(j+a[i]<=s)temp[j+a[i]]+=coeff[j];
    coeff[j]=temp[j];
    coeff[j]%=p;
   }
//if(i==1)for(int j=0;j<=10;j++)cout<<temp[j]<<endl;
}

cout<<coeff[s]<<endl;



 return 0;
 
 
}