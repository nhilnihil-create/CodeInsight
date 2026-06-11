#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};

ll modpow(ll a, ll p)
{
  if (p == 0)
    return 1;
  if (!(p % 2))
  {
    ll halfP = p / 2;
    ll half = modpow(a, halfP);
    return half * half % mod;
  }
  else
  {
    return a * modpow(a, p - 1) % mod;
  }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y;
    cin >> X >> Y;

    int num = 2000100;
    vector<ll> fact(num), ifact(num);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < num; i++)
    {
      fact[i] = fact[i - 1] * i;
      fact[i] %= mod;
    }
    for (int i = 0; i < num; i++)
    {
      ifact[i] = modpow(fact[i], mod - 2);
      ifact[i] %= mod;
    }

    auto comb = [&] (ll a, ll b) {
      return fact[a] * ifact[a-b] % mod * ifact[b] % mod;
    };

    ll m = (2 * X - Y) / 3;
    ll n = (2 * Y - X) / 3;
    if (m < 0 || n < 0 || (X + Y) % 3) {
      cout << 0 << endl;
      return 0;
    }
    cout << comb(m+n, n) << endl;
    return 0;
}