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
  ll M;
  cin >> M;
  ll ans = 0;
  ll keta = 0, sum = 0;
  REP(i, M){
    ll d; ll c;
    cin >> d >> c;
    keta += c;
    sum += d * c;
    // if(sum <= 9) continue;
    // ans += (sum-1) / 9;
    // sum %= 9;
    // if(sum == 0) sum++;
  }
  // assert(sum <= 9);
  ans += (sum-1) / 9;
  ans += keta-1;
  cout << ans << endl;
  return 0;
}
