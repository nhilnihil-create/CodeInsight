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

ll n;
vector<vector<Pair>> g; // (もう一方の頂点, 辺番号)
ll a, b;
queue<ll> q;

void Main() {
  cin >> n;
  g.assign(n, vector<Pair>());

  REP(i, n - 1) {
    cin >> a >> b;
    a--;
    b--;
    g[a].emplace_back(b, i);
    g[b].emplace_back(a, i);
  }
  vll edge_color(n - 1, -1); // -1 は色ぬられてない

  ll node = 0;
  q.push(node);

  ll max_color = 0;
  while(!q.empty()) {
    node = q.front();
    // cout << "node: " << node << endl;
    // cout << "edge_color: ";
    // COUTA(i, edge_color);
    ll used_color = -1;
    vll target_edge;
    REP(i, g[node].size()) {
      if (edge_color[g[node][i].second] == -1) {
        target_edge.push_back(g[node][i].second);
        q.push(g[node][i].first);
        // cout << "push: " << g[node][i].first << endl;
      }
      else {
        used_color = edge_color[g[node][i].second];
      }
    }
    ll color=0;
    // cout << "target_edge: ";
    // COUTA(i, target_edge);
    for(ll item : target_edge) {
      if (color != used_color) {
        edge_color[item] = color;
        max_color = max(max_color, color);
      }
      else {
        color++;
        edge_color[item] = color;
        max_color = max(max_color, color);
      }
      color++;
    }
    // cout << "pop: " << q.front() << endl;
    q.pop();
  }

  COUT(max_color+1);
  for(ll e: edge_color) {
    COUT(e+1);
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
