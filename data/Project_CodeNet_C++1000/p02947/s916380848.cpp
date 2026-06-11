#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll func(ll x) {
  return x * (x - 1) / 2;
}

void solve() {
  int n;
  cin >> n;
  map<string, ll> mp;
  rep(i,n) {
    string s;
    cin >> s;
    sort(ALL(s));
    mp[s]++;
  }
  ll ans = 0;
  for (auto p: mp) {
    if (p.second == 1) continue;
    ans += func(p.second);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}