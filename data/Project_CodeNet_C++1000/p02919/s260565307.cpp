//
// Created by Koki Igarashi on 7/29/20.
//
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef int Int;
typedef pair<Int, Int> pii;
typedef pair<Int, double> pid;
typedef pair<double, double> pdd;
typedef pair<Int, pii> pip;
typedef pair<pii, Int> ppi;
typedef pair<double, Int> pdp;
typedef vector<Int> veci;
typedef vector<double> vecd;
typedef vector<int> veci;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<pii> vecpii;
typedef vector<ppi> vecppi;
typedef vector<veci> mati;
typedef vector<vecll> matll;
typedef vector<vecd> matd;
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (x).size()
#define CLR(x) memset(x,0,sizeof x)
#define pdebug() printf("%d\n",__LINE__)
#define REP(i, a, b) for(int i = (a);i <= (b);i++)
#define FORO(i, n) REP(i,0,(int)n-1)
#define FORI(i, n) REP(i,1,(int)n)
#define FORIT(i, t) for(auto i = t.begin();i != t.end();i++)
#define eps 1e-6
#define sqr(x) ((x)*(x))
#define dist(_a, _b) sqrt(sqr(_a.A-_b.A)+sqr(_a.B-_b.B))
#define norm(_a) sqrt(sqr(_a.A)+sqr(_a.B))

#define DUMP(a) do { std::cout << #a " = " << (a) << ", "; } while(false)
#define DUMPLN(a) do { std::cout << #a " = " << (a) << std::endl; } while(false)

template<typename T, typename U>
inline void getMin(T &a, U b) { if (a > b) a = b; }
template<typename T, typename U>
inline void getMax(T &a, U b) { if (a < b) a = b; }
template<typename T>
vector<T> getVector(const int n) { return vector<T>(n); }
template<typename T>
vector<T> getVector(const int n, const T a) { return vector<T>(n, a); }
template<typename T>
vector<T> getEmptyVector() { return vector<T>(); }
template<typename T>
void appendAll(vector<T> &a, vector<T> b) { a.insert(a.end(), b.begin(), b.end()); }
// #define X first
// #define Y second
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll MOD = 1000000007;
const int MAXN = 1 << 17;
const int inf = 1 << 20;
const int NIL = -inf;
int popcount(int x) { return __builtin_popcount(x); }

class BIT {
  int n;
  vecpii bit;
  const pii INIT = make_pair(-1, -1);

 public:

  BIT(int n) : n(n) {
      init(n);
  }

  void init(int n){
      bit.resize(n + 1);
      FORO(i, n + 1) {
          bit[i] = INIT;
      }
  }

  void update_2max(pii &x, int a) {
      if (a > x.first) {
          x.second = x.first;
          x.first = a;
      } else if (a > x.second) {
          x.second = a;
      }
  }

  void update(int i, int x) {
      while (i <= n) {
          update_2max(bit[i], x);
          i += i & -i;
      }
  }

  pii get_2max(int i) {
      pii ret = INIT;
      while (i > 0) {
          update_2max(ret, bit[i].first);
          update_2max(ret, bit[i].second);
          i -= i & -i;
      }
      return ret;
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    veci P(N);
    FORO(i, N) cin >> P[i];

    vecpii lig(N);
    BIT bit1(N);
    FORO(i, N) {
        lig[i] = bit1.get_2max(N - P[i]);
        if(lig[i].first < 0) lig[i].first++;
        if(lig[i].second < 0) lig[i].second++;
         bit1.update(N - P[i] + 1, i + 1);
    }

    vecpii rig(N);
    BIT bit2(N);
    for(int i = N - 1;i >= 0;i--) {
        rig[i] = bit2.get_2max(N - P[i]);
        rig[i].first = N - rig[i].first + 1;
        rig[i].second = N - rig[i].second + 1;
        getMin(rig[i].first, N + 1);
        getMin(rig[i].second, N + 1);
        bit2.update(N - P[i] + 1, N - i);
    }

    ll ans = 0;
    FORO(i, N) {
        pii &li = lig[i], &ri = rig[i];
        ans += (ll)P[i] * (li.first - li.second) * (ri.first - i - 1);
        ans += (ll)P[i] * (ri.second - ri.first) * (i - li.first + 1);
    }

    cout << ans << endl;

    return 0;
}