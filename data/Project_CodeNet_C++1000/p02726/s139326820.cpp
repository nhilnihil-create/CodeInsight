#include <bits/stdc++.h>
using namespace std;

// TYPEDEF
// ----------------------------------------
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> Pair;
typedef vector<ll> vll;
typedef vector<vector<ll>> Graph;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> Pll;
typedef queue<ll> qll;

// REPEAT
// ----------------------------------------
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REPA(i,a) for(ll i=0;i<(ll)(a.size());i++);
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define COUT(a) cout << (a) << endl;
#define ENDL(a) cout << endl;
#define COUTA(i,a) for(ll i=0;i<(ll)(a.size());i++) {cout << (a)[i] << " ";} cout << endl;

// UTIL
// ----------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())

// DEBUG
// ----------------------------------------
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif

template <typename T>
void debugV(const vector<T> v) {
#ifdef _DEBUG
  rep(i, v.size()) {
    cout << i << ":" << v[i] << " ";
  }
  cout << endl;
#else
  (void)v;
#endif
}

// BIT FLAG
// ----------------------------------------
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000
const unsigned int BIT_FLAG_8 = (1 << 8); // 0000 0001 0000 0000
const unsigned int BIT_FLAG_9 = (1 << 9); // 0000 0010 0000 0000
const unsigned int BIT_FLAG_10 = (1 << 10); // 0000 0100 0000 0000
const unsigned int BIT_FLAG_11 = (1 << 11); // 0000 1000 0000 0000

// CONST
// ----------------------------------------
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI=3.14159265358979323846; // or M_PI
constexpr int MOD = 1000000007;


void Main() {
  ll n, x, y;
  cin >> n >> x >> y;

  Graph g(n, vll(n, 0));

  REP(i, n) {
    FOR(j, i + 1, n - 1) {
      g[i][j] = j - i;
    }
  }

  // REP(i, n) {
  //   REP(j, n) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }


  ll x_ri = x - 1;
  ll y_ri = y - 1;

  // yと下方向
  ll step = 1;
  ll step_y;
  FOR(i, x_ri, n - 1) {
    g[i][y_ri] = min(g[i][y_ri], step);
    step_y = g[i][y_ri];
    FOR(j, i, n - 1) {
      g[i][j] = min(g[i][j], step_y + abs(y_ri - j));
    }
    step++;
  }

  // 上方向
  step = 2;
  FORD(i, x_ri - 1, 0) {
    g[i][y_ri] = min(g[i][y_ri], step);
    step_y = g[i][y_ri];
    FOR(j, i, n - 1) {
      g[i][j] = min(g[i][j], step_y + abs(y_ri - j));
    }
    step++;
  }

  vll ans(n);

  // REP(i, n) {
  //   REP(j, n) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  REP(i, n) {
    FOR(j, i + 1, n - 1) {
      ans[g[i][j]]++;
    }
  }

  FOR(i, 1, n - 1) {
    COUT(ans[i]);
  }

}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}

/*

3 2
*/
