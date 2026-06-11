#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  priority_queue<P, vector<P>, greater<P>> pq;
  string ans = "Yes";
  rep(i,n) {
    int a, b; cin >> a >> b;
    pq.push(make_pair(b,a));
  }
  ll t = 0;
  while(!pq.empty()) {
    auto p = pq.top(); pq.pop();
    int shimekiri = p.first;
    int work = p.second;
    t += work;
    if (t > shimekiri) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}