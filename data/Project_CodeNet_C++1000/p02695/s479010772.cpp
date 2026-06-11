#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

vector<ll> a;
vector<ll> b;
vector<ll> c;
vector<ll> d;
ll n;
ll m;
ll q;
ll ans = 0;
void dfs(vector<ll> A) {
  if (A.size() == n) {
    ll point = 0;
    for (long long i = 0; i < q; i++) {
      if ((A.at(b.at(i)) - A.at(a.at(i))) == c.at(i)) {
        point += d.at(i);
      }
    }
    ans = max(ans, point);
    return;
  }
  ll first = 1;
  if (A.size() != 0) {
    first = A.back();
  }
  for (long long i = first; i <= m; i++) {
    vector<ll> tmp(A);
    tmp.push_back(i);
    dfs(tmp);
  }
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);

  for (long i = 0; i < q; i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  dfs({});
  cout << ans << endl;
}
