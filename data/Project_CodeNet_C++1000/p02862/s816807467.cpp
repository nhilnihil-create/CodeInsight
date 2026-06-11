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

ll x, y;
vector<Pair> toutatsu;

ll kaijyo(ll n) {
  ll ans = 1;
  FOR(i, 1, n) {
    ans = (ans * i) % MOD;
  }
  return ans;
}

// MOD での a の逆元 a^{-1} を計算する
ll modinv(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

void Main() {
  cin >> x >> y;

  REP(a, y / 2 + 1) { // Aパターン (i + 1, j + 2) の個数
    if (a == ld(2 * y - x) / 3) {
      ll b = (y - 2 * a); // Aパターンの個数から想定されるBパターン (i + 2, j + 1) の数
      toutatsu.emplace_back(a, b);
    }
  }

  if (toutatsu.size() == 0) {
    COUT(0);
  }
  else {
    ll a = toutatsu[0].first;
    ll b = toutatsu[0].second;
    COUT((kaijyo(a+b) * modinv(kaijyo(a)) % MOD) * modinv(kaijyo(b)) % MOD);
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
