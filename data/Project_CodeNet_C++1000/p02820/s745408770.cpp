#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  map<char, int> mp;
  mp['r'] = p;
  mp['s'] = r;
  mp['p'] = s;
  vector<bool> seen(n, false);
  vector<bool> win(n, false);
  ll ans = 0;
  rep(i,n) {
    if (seen.at(i)) continue;
    for (int j = i; j < n; j += k) {
      if (j >= n) continue;
      seen.at(j) = true;  
      if (!(j - k < 0) && (t.at(j-k) == t.at(j) && win.at(j-k))) continue;

      win.at(j) = true;      
      ans += mp.at(t.at(j));
    }
  }
  cout << ans << endl;
  
  return 0;
}