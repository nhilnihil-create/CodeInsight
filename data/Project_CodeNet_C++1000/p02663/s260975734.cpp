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
  while(b>0)
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

void fill()
{
inv[0]=1;
fac[0]=1;

for(int i=1;i<=N;i++)
{
  fac[i]=fac[i-1]*i%p;
  inv[i]=powM(fac[i],p-2,p);
}

}
*/
//ld dp[2001][2001];

//ll dp[3001][3001];  // dp[i][j] ways to make sum i using j numbers.


int main()
{  fast

ll h1,m1,h2,m2,k;cin>>h1>>m1>>h2>>m2>>k;
ll a=0;

if(h2<h1)h2+=24;

if(m1>=m2)
  {
    a+=60+m2-m1;
    h2--;
}
else a+=m2-m1;

a+=60*(h2-h1);

cout<<max(a-k,0LL)<<"\n";


 return 0;

}
