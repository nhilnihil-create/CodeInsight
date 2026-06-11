#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

/* exchange */
#define chmin(a, b) (a) = min((ll)(a), (ll)(b))
#define chmax(a, b) (a) = max((ll)(a), (ll)(b))

/* output */
#define I(x) cin >> x;
#define D(x) cerr << (x) << " ";
#define BR cerr << "\n";
#define P(x) cout << (x) << endl;
#define FIX cout << fixed << setprecision(10);

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N = 0;
ll ret = 0;
string s;

ll modPow(ll x, ll y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  if (y % 2 == 0) return modPow((x * x) % MOD, y / 2);
  else return (x * modPow((x * x) % MOD, y / 2)) % MOD;
}

vl table1(ARRAY, -1);
vl table2(ARRAY, -1);

ll dp1(ll k) { //すでにLより小さい前提
  if (table1[k] != -1) return table1[k];
  return table1[k] = modPow(3, N - k);
}

ll dp2(ll k) { //Lより小さいか未定
  if (table2[k] != -1) return table2[k];
  int d = s[k] - '0';
  ll ans = 0;
  if (d == 1) {
    if (k == N-1) ans = 3;
    else ans = 2 * dp2(k+1) + dp1(k+1);
  } else {
    if (k == N-1) ans = 1;
    else ans = dp2(k+1);
  }
  return table2[k] = ans % MOD;
}

int main(void){
  
  I(s);
  N = s.size();

  ret = dp2(0);

  P(ret);

}
