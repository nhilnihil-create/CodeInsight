#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll P(ll n, ll r){
  if(n < r) return 0;
  ll res = 1, num = n;
  rep(i, r){
    res = (res * num) % MOD;
    num--;
  }
  return res % MOD;
}

int n, k;
vector<vector<int>> G;

void rec(int v, int p, ll &res, int depth) {
    int chs = 0;
    for (auto ch : G[v]) {
        if (ch == p) continue;
        ++chs;
        rec(ch, v, res, depth+1);
    }
    if (depth == 0) res = res * P(k-1, chs) % MOD;
    else res = res * P(k-2, chs) % MOD;
}

int main(){ 
    cin >> n >> k;
    G.resize(n);
    rep(i, n-1){
      int a, b; cin >> a >> b; a--; b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }

  ll res = k;
  rec(0, -1, res, 0);
  cout << res << ln;
}
