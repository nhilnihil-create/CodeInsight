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
#define vi vector<int>

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

ll ans;
ll dp[1000005][2];

int main(void) {
  //解説あり
    string x, N = "x";
    cin >> x;
    N += x;
    dp[0][1] = 1;
    rep(i, 1, sz(N)){
      ll d = (ll)(N[i] - '0');
      dp[i][0] = min(dp[i-1][0]+d, dp[i-1][1]+10-d);
      dp[i][1] = min(dp[i-1][0]+d+1, dp[i-1][1]+10-d-1);
      //printf("%lld %lld\n", dp[i][0], dp[i][1]);
    }
    
    ans = dp[sz(N)-1][0];
    cout << ans << endl;
    
    return 0;
}



