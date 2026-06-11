#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;
template<typename T>
struct Edge {
    int u, v;
    T cost;
    Edge(int u, int v, T c) : u(u), v(v), cost(c) {}
    bool operator< (const Edge &e) const {return cost < e.cost;}
};

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans = -LINF;
int z;

int main(void) {
  int N;
  int K;
  cin >> N >> K;
  vector<int> P(N, 0);
  vector<ll> C(N, 0);
  rep(i, 0, N) {
    cin >> P[i];
    P[i]--;
  }
  rep(i, 0, N) cin >> C[i];

  rep(i, 0, N) {
    int size = 0;
    ll sum = 0;
    int pos = i;
    do {
      sum += C[P[pos]];
      pos = P[pos];
      size++;
    } while (pos != i);

    if (sum<=0 || K<=size) {
      
      int p = i;
      ll x = 0;
      rep(j, 0, min(size,K)) {
        x += C[P[p]];
        p = P[p];
        ans = max(ans, x);
      }

    } else {
      int q = K/size, r = K%size+size;
      sum = sum*(q-1);
      if (q!=0) ans = max(ans, sum);
      pos = i;
      rep(j, 0, r) {
        sum += C[P[pos]];
        pos = P[pos];
        ans = max(ans, sum);
      }
    }
  }
    
  
    
  cout << ans << endl;
  return 0;
}



