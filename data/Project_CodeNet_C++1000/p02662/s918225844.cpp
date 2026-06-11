#include<bits/stdc++.h>
//#include<unordered_map>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vii         vector<pair<ll,ll> >
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define rep1(i,a,b) for(ll i=a;i<= b;i++)
#define PI          3.14159
#define MAX         1000001
#define fast_io      ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define scan(var)    scanf("%lld",&var)
#define print(var)   printf("%lld\n", var);
#define BLOCK 317
#define double       long double
#define mod          998244353
#define levelo        31
#define hell1        1000000009
using namespace std;
ll dp[3001][3001];
vector<ll> v1;
ll solvedp(ll index,ll val)
{
  if(index == 0 && val == 0)
  {
    return 1;
  }
  if(index == 0)
  {
    return 0;
  }
  if(dp[index][val] != -1)
  {
    return dp[index][val];
  }
  ll num = (2*solvedp(index - 1,val))%mod;
  if(v1[index] <= val)
  {
    num = (num + solvedp(index - 1,val - v1[index]))%mod;
  }
  dp[index][val] = num;
  return num;
}
int main()
{
  fast_io
  ll t;
  t = 1;
  while(t--)
  {
    ll n,s;
    cin >> n >> s;
    memset(dp,-1,sizeof(dp));
    v1.pb(-1);
    rep(i,0,n)
    {
      ll num;
      cin >> num;
      v1.pb(num);
    }
    cout << solvedp(n,s);
  }
  return 0;
}