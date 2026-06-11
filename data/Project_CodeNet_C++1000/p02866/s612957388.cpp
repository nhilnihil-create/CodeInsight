#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)998244353;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
long long combination(long n, long r, long long mod) {
  //nCrを返す　O(r)
  // 逆元はその場で対応
  if (n < r) swap(n, r);
  long long bunbo = 1;
  long cnt = r;
  while (0 < cnt) {
    bunbo *= cnt;
    bunbo % mod;
    cnt--;
  }
 if (bunbo == 0) return 1;
  long long bunsi = 1;
  cnt = 0;
  while (cnt < r) {
    bunsi *= (n  - cnt);
    bunsi %= mod;
    cnt++;
  }
  return bunsi / bunbo % mod;
}
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  map<int, int> uo{};
  REP(i, N) {
    cin >> d[i];
    uo[d[i]]++;
  }
  if(d[0]!=0||uo[0]>=2){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  for(auto s:uo){
    if (s.first == 0) continue;
    int num = s.first,id=s.second;
    if (uo[num - 1] == 0) ans = 0;
    ans *= longpow(uo[num-1],uo[num],MOD);
    ans %= MOD;
  }
  cout << ans << endl;
 }