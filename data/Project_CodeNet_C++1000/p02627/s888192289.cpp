#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl

#define lpair pair<ll, ll>

int main()
{
  string n;
  cin >> n ;
  string ans = (n[0] >= 'a' && n[0] <= 'z') ? "a" : "A";

  cout << ans << endl;

  return 0;
}