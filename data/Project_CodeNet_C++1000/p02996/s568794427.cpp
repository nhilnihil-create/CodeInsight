#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<pair<ll,ll>> p(n);
  rep(i,n) {
    ll a, b;
    cin >> a >> b;
    p[i].first = b;
    p[i].second = a;
  }
  sort(p.begin(), p.end());
  
  ll time = 0;
  bool ok = true;
  rep(i,n) {
    time += p[i].second;
    if (time > p[i].first) {
      ok = false;
      break;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}