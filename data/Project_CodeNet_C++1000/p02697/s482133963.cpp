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


int main(void) {
  int N, M;
  cin >> N >> M;
  if (N%2==1) rep(i, 1, M+1) printf("%d %d\n", i, N-i+1);
  else {
    int x = (((N-2)/2+1)/2);
    rep(i, 1, M+1) {
      if (i<=x) printf("%d %d\n", i, N-i+1);
      else printf("%d %d\n", i, N-i);
    }
  
  }
    

    return 0;
}




