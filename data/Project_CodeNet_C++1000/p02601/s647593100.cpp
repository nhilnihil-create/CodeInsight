
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
  ll a,b,c,k;
  cin >> a >> b >> c >> k;

  ll time = 0;
  while(a >= b)
  {
    b *= 2;
    time++;
  }
  while(b >= c)
  {
    c *= 2;
    time++;
  }

  cout << fixed << (time <= k ? "Yes" : "No") << endl;

  return 0;
}