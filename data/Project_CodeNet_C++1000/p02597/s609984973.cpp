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
  ll n;
  string s;
  cin >> n >> s;
  ll wcnt = 0;
  ll rcnt = 0;
  rep(i, n) {
    if (s.at(i) == 'W') wcnt++;
    if (s.at(i) == 'R') rcnt++;
  }
  ll ans = 0;
  rep(i, rcnt) {
    if (s.at(i) == 'W') ans++;
  }
  cout << ans << endl;
  return 0;
}