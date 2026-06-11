#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
ll dp[100005][2];
//Classic digit dynamic programming
string s;

ll recur(ll pos,ll flag)
{
  if(pos >= s.length())
  {
      return 1ll;
  }
  else if(dp[pos][flag] != -1)
  {
      return dp[pos][flag];
  }
  else
  {
      if(flag)
      {
          return dp[pos][flag] = ((recur(pos + 1,flag) % mod)*3)%mod;
      }
      else
      {
          ll limit = s[pos] - '0';
          if(limit == 0)
          {
              return dp[pos][flag] = recur(pos + 1,flag)%mod;
          }
          else
          {
              return dp[pos][flag] = ((((recur(pos + 1,flag)%mod)*2)%mod + (recur(pos + 1,1)))%mod)%mod;
          }
          
      }
      
  }
  
}
void Compute()
{
    KAKA
    memset(dp,-1,sizeof(dp));
    ll ways = 0;
    ways += recur(0,0);
    cout<<ways<<"\n";
}
int main()
{
    KAKA
   // string s;
    cin>>s;
    Compute();
}