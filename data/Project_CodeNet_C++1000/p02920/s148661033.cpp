#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  ll n; cin >> n;
  ll m = 1ll<<n;
  V s(m);
  rep(i, m) cin >> s[i];
  sort(all(s));
  reverse(all(s));

  multiset<int> S;
  S.insert(s[0]);
  s[0] = -1;

  rep(i, n) {
    stack<int> sta;
    for (auto e : S) sta.push(e);
    int j = 0;
    while (!sta.empty()) {
      int x = sta.top(); sta.pop();
      while (j < m && (s[j] < 0 || x <= s[j])) j++;
      if (j == m) {
        cout << "No" << endl;
        return 0;
      }
      S.insert(s[j]);
      s[j] = -1;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
