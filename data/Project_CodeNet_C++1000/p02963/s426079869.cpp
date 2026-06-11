#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}



int main(void)
{
  ll s;
  cin >> s;
  ll v = 1000000000;
  ll x = (v - s%v)%v;
  ll y = (s+x)/v;
  printf("0 0 1000000000 1 %lld %lld\n", x, y);
}
