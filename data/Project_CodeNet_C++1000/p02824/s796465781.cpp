#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpl = vector<pll>;
using vvll = vector<vll>;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(ll i=0;i<((ll)n);i++)
#define REP1(i,n) for(ll i=1;i<((ll)n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vll a(n);
  REP(i, n)cin >> a[i];

  sort(ALL(a), greater<ll>());
  vll remind(n + 1);
  REP(i, n)remind[i + 1] += remind[i] + a[i];

  auto check = [&](ll k) {
      if (k < p)
          return true;
	  if (m + a[k] < a[p - 1])
		  return false;

      ll can_vote = (p - 1) * m + (n - k) * m;
	  can_vote += (k - p + 1) * (m + a[k]) - (remind[k] - remind[p-1]);
	  return m * v <= can_vote;
  };

  ll ans = 0;
  REP(i, n) {
      if (check(i))
          ans++;
  }
  cout << ans << endl;

}
