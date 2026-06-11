
#include <bits/stdc++.h>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl
#define DEV_VAL 1000000007

int main()
{
  ll n;
  cin >> n;

  ll val = 8 - ((n-400) /200);

  cout << fixed << val << endl;

  return 0;
}