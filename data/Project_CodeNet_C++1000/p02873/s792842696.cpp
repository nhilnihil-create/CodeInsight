#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  vector<ll> a(s.size()+1, 0);

  rep(i,s.size()) if (s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);
  for (int i = s.size()-1; i >= 0; i--) {
    if (s[i] == '>') a[i] = max(a[i],a[i+1]+1);
  }

  cout << accumulate(a.begin(),a.end(),ll(0)) << endl;

  return 0;
}
