#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;



int main(){
  string S;
  cin >> S;
  vector<ll> cnt(2019, 0);
  int N = S.size();
  ll x = 0;
  ll ans = 0;
  cnt[0] = 1;
  REP(i, N){
    x *=10;
    x += S[i] - '0';
    x %= 2019;
    ans += cnt[x];
    cnt[x]++;
    vector<ll> ncnt(2019, 0);
    REP(j, 2019){
      int id = (j * 10) % 2019;
      ncnt[id] = cnt[j];
    }
    cnt = ncnt;
  }
  cout << ans << endl;
  return 0;
}