#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, bool>> vec(n);
  rep(i, n) vec[i] = make_pair(0, false);
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    if (s == 1 && c == 0 && n != 1) {
      cout << -1 << endl;  
      return 0;      
    }
    if (vec[s-1].second && vec[s-1].first != c) {
      cout << -1 << endl;  
      return 0;
    }
    vec[s-1].first = c;
    vec[s-1].second = true;
  }
  
  if (vec[0].first == 0 && vec[0].second && n != 1) {
    cout << -1 << endl;
  } else {
    int ans = 0;
    rep(i, n) {
      int d = vec[i].second ? vec[i].first : (i == 0 && n != 1  ? 1 : 0);
      int p = d * pow(10, n-(1+i));
      ans += p;
    }
    cout << ans << endl;
  }
  return 0;
}