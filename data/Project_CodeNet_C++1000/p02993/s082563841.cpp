#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const double eps = 1E-18;

int main()
{
  string s;
  cin >> s;
  string ans = "Good";
  if (s[0]==s[1] || s[1]==s[2] || s[2]==s[3]) {
    ans = "Bad";
  }
  cout << ans << endl;
  return 0;
}