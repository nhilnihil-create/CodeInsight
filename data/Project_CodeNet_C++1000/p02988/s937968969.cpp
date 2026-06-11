#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
const ll INF = 1E+18;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int ans = 0;
  rep(i, n-2) {
    vector<int> now;
    rep(j, 3) {
      now.push_back(p[i+j]);
    }
    sort(now.begin(), now.end());
    if (now[1]==p[i+1]) ans++;
  }
  cout << ans <<endl;
  return 0;
}