#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<ll> a(n+1);

  for (int i=0; i<n; i++) {
    if (s[i] == '<') {
      a[i+1] = max(a[i+1], a[i]+1);
    }
  }

  for (int i=n-1; i>=0; i--) {
    if (s[i] == '>') {
      a[i] = max(a[i], a[i+1]+1);
    }
  }

  ll ans = 0;
  for (auto ai : a) {
    ans += ai;
  }
  cout << ans << endl;
}