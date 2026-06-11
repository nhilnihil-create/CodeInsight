#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long int
#define pb push_back
#define RONALDO            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl "\n"
#define pii pair<ll, ll>
#define ff first
#define ss second
#define mod 1000000007
#define vi vector<ll>
#define mi map<ll, ll>
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
const int N = 1e5 + 5;
//LOVE U MESSI && CRistiano !!

//INSPIRATIONAL MICHAEL PHELPS && USAIN BOLT !!

int main()
{
  RONALDO;
  // ll t;
  // cin >> t;
  // while (t--)
  // {
  ll n, p=1,q=1,r=1;
  cin >> n;
  ll ans;
  for (ll j = 0; j < n; j++)
  {
    p = ((p%mod) * 10)%mod;
    q = ((q%mod) * 9)%mod;
    r = ((r%mod) * 8)%mod;
  }
  ans= (p%mod - (2*q)%mod + r%mod)%mod;
  if(ans<0)
    cout << ans%mod + mod << endl;
  else
    cout << ans%mod<< endl;
  }