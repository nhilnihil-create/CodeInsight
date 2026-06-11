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

int main()
{
  ll n;
  string s;
  cin >> n >> s;
  int ans = 0;
  reps(i, 0, 1000)
  {
    int idx = 0;
    char v[4];
    sprintf(v, "%03d", i);
    rep(j, 3)
    {
      char x = v[j];
      bool isFind = false;
      while(idx < n)
      {
        if(x == s[idx])
        {
          idx++;
          isFind = true;
          break;
        }
        idx++;
      }
      if(!isFind)
      {
        break;
      }
      else if(j == 2)
      {
        ans++;
      }
      
    }
  }

  cout << fixed << ans << endl;

  return 0;
}