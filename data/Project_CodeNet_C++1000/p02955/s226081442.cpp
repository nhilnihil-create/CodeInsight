#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
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


vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main() {
  ll N, K; cin >> N >> K;
  Vll A(N);
  rep(i, N) cin >> A[i];

  ll sum = 0;
  rep(i, N) sum += A[i];
  
  auto div = divisor(sum);
  reverse(ALL(div));

  for (auto e : div) {
    Vll b(N);
    rep(i, N) {
      b[i] = A[i] % e;
    }
    sort(ALL(b));

    Vll s1(N+1), s2(N+1);
    rep(i, N) {
      s1[i+1] += s1[i] + b[i];
      s2[i+1] += s2[i] + e - b[N-i-1];
    }

    ll cmin = INFll;
    rep(i, N+1) {
      chmin(cmin, max(s1[i], s2[N-i]));
    }  
    if (cmin <= K) {
      cout << e << endl;
      return 0;
    }
  }
}
