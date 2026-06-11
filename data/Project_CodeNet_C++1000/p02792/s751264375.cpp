#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

P f(int a) {
  int x = a % 10;
  int y = a;
  while(a) {
    y = a;
    a /= 10;
  }
  return P(x, y);
}
int main()
{
  int n;
  cin >> n;
  ll ans = 0;
  map<P, int> mp;
  for (int i = 1; i <= n; i++) {
    P p = f(i);
    mp[p]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    ans += it->second * mp[make_pair(it->first.second, it->first.first)];
  }
  cout << ans << endl;
}