#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool calc(ll n) {
  vector<pair<ll, ll>> p;
  for(int i = 2; i*i <= n; i++) {
    if(n % i != 0) continue;
    int cnt = 0;
    while(n % i == 0) {
      n /= i;
      cnt++;
    }
    p.push_back({i, cnt});
  }
  if(n != 1) p.push_back({n, 1});
  if(p.size() == 1) {
    if(p[0].second == 1) {
      return true;
    }
  }
  return false;
}

int main() {
  int x;
  cin >> x;
  for(int i = x; i <= 100003; i++) {
    bool ok = calc(i);
    if(ok) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
