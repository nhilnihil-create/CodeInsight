#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795

ll f(ll a)
{
  ll cnt=0,i;
  if (a==2)return 1;
  for(i=2;i*i<a;i++)
  {
if(a%i==0)cnt+=2;
  }
  if(i*i==a)cnt++;
  return cnt;
}

//vl a(1001);

ll powM(ll a,ll b, ll m)
{ 
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans%m;
}

ll g(ll a,ll n)
{
  if(a<0)return ((a%n)+n)%n;
  else return a%n;
}
char A[51][51]={0};
char B[51][51]={0};

ll solve(ll x,ll y,ll na,ll ma,ll nb,ll mb)
{
  ll cnt=0;
  for(int i=1;i<=na;i++)
  {
    //ll temp1=x+i;
    if(x+i<=0)continue;
    else if(x+i>nb)break;
    else 
      {
        for(int j=1;j<=ma;j++)
        {
          if(y+j<=0)continue;
          else if(y+j>mb)break;
          else 
            {
              cnt+=A[i][j]=='1'&&B[i+x][j+y]=='1';
            }
        }
      }
  }
  return cnt;
}

int main()
{
string s,t;cin>>s>>t;
ll cnt=0;
for(int i=0;i<3;i++)cnt+=s[i]==t[i];
  cout<<cnt<<"\n";
  return 0;

}
