#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define li long int
#define ld long double
#define lld long long double

#define pb push_back
#define mk make_pair
#define F first
#define S second

#define all(v) (v).begin(),(v).end()
#define fill(a) memset(a, 0, sizeof(a))

const int MX = 1e6;
const int MI = -1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;

#define rep(i, n) for(int i=0; i<n; i++)

const int mod=1e9+7;
inline int add(int x,int y)
{
  x+=y;
  if (x>=mod)
    return x-mod;
  return x;
}
inline int sub(int x,int y)
{
  x-=y;
  if (x<0)
    return x+mod;
  return x;
}
inline int mul(int x,int y)
{
  return (x*1ll*y)%mod;
}
inline int power(int x,int y)
{
  int ans=1;
  while(y)
    {
      if (y&1) ans=mul(ans,x);
      x=mul(x,x);
      y>>=1;
    }
  return ans;
}
inline int inv(int x)
{
  return power(x,mod-2);
}
inline int gcd(int x, int y)
{
  return(y!=0)?gcd(y, x%y):x;
}
inline ll nPr(int n, int r)
{
  ll i,result=1;
  rep(i,r)
    {
      result*=(ll)(n-i);
    }
  return result;
}
inline ll nCr(int n,int r)
{
  ll i,result=1;
  rep(i,min(r,n-r))
    {
      result*=(ll)(n-i);
      result/=(ll)(i+1);
    }
  return result;
}
bool prime(int n)
{
  for (int i=2; i<n/2; i++)
    {
      if(n%i==0)
	return false;
    }
  return true;
}

/*------------CODE-----------*/

int main()
{
  IOS;
  int a, b, k;
  cin >> k;
  cin >> a >> b;
  for (int i=min(a, b); i<=max(a, b); i++)
    {
      if (i%k==0)
	{
	  cout << "OK" << endl;
	  return 0;
	}
    }
  
  cout << "NG" << endl;
  return 0;
}
