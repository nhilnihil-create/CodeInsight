#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define FI(i,a,n) for(int i=a; i<=n; i++)
#define RFI(i,n,a) for(int i=n; i>=a; i--)
#define FLL(i,a,n) for(ll i=a; i<=n; i++)
#define RFLL(i,n,a) for(ll i=n; i>=a; i--)
#define vi vector<int>
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pi pair<int, int>
#define GCD(a,b) __gcd(a,b)
#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define debug(x) cout << x << endl
#define MOD 1000000007
#define INF LLONG_MAX
#define PI 3.14159265359
using namespace std;

ll power(ll x, ll n, ll mod=MOD)
{
   ll ans = 1;
   x %= mod;
   while(n)
   {
     if(n&1) ans = (ans * x ) % mod;
     n >>= 1;
     x = (x*x)%mod;
   }
   return ans;
}

int main()
{
	fastio
  string s;
  cin >> s;
  int n = s.length();
  ll dp[n+1][13]={};
  if(s[n-1]!='?') dp[n-1][s[n-1]-'0']=1;
  else
  {
    for(int i=0; i<10; i++) dp[n-1][i]=1;
  }
  for(int i=n-2; i>=0; i--)
  {
    if(s[i]!='?')
    {
      int a = s[i]-'0';
      ll rem = ( a * power(10, n-i-1, 13) ) % 13;
      for(int j=0; j<13; j++) dp[i][(j + rem)%13] = dp[i+1][j];
      /* if(dp[i][rem]==0) dp[i][rem] = 1; */
    }
    else
    {
      for(int z=0; z<=9; z++)
      {
        int a = z;
        ll rem = ( a * power(10, n-i-1, 13) ) % 13;
        for(int j=0; j<13; j++) dp[i][(j + rem)%13] += dp[i+1][j], dp[i][(j+rem)%13]%=MOD;
        /* if(dp[i][rem]==0) dp[i][rem] = 1; */
      }
    }
  }
  cout << dp[0][5];





	return 0;
}



