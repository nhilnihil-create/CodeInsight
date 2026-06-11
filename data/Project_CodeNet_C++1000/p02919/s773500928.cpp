#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> p(n), x(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
    x.at(p.at(i)) = i;
  }
  
  multiset<ll> s;
  s.insert(x.at(n));
  s.insert(-1);
  s.insert(-1);
  s.insert(n);
  s.insert(n);
  ll ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    s.insert(x.at(i));
    auto now = s.find(x.at(i));
    auto b = now;
    b--;
    auto a = b;
    a--;
    auto c = now;
    c++;
    auto d = c;
    d++;
    
    ll keep = (*now - *b) * (*d - *c) + (*b - *a) * (*c - *now);
    ans += keep * i;
  }
  
  cout << ans << '\n';
}