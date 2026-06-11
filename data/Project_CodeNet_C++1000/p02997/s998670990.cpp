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
  ll n, k; cin >> n >> k;
  ll kmax = (n-1) * (n-2) / 2;
  if (k > kmax) {
    cout << "-1" << endl;
    return 0;
  }

  vector<P> E;
  rep(i, n-1) {
    E.push_back(P(0, i+1));
  }
  ll added = 0;

  if (kmax - added == k) {
    cout << (added + n - 1) << endl;
    for (auto e : E) {
      cout << (e.first+1) << " " << (e.second+1) << endl;
    }
    return 0;
  }


  rep2(i, 1, n) rep2(j, i+1, n) {
    E.push_back(P(i, j));
    ++added;
    if (kmax - added == k) {
      cout << (added + n - 1) << endl;
      for (auto e : E) {
        cout << (e.first+1) << " " << (e.second+1) << endl;
      }
      return 0;
    }
  }
  return 0;
}
