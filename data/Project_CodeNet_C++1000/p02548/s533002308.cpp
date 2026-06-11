//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word
// kuch ni ho rha to kya pta binary search ho
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
#define sz 100005
ll inf = 1e18;
ll power(ll x, ll n, ll mod)
{
  ll res = 1;
  x %= mod;
  while (n)
  {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res%mod;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ll n;
  cin>>n;
  ll ans=0;
  for(ll i=1;i<=n-1;i++)
    ans=ans+(n-1)/i;
  cout<<ans;
  return 0;
}