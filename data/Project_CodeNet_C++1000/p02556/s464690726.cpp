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

ll ans;

int main(void) {
    int N;
    cin >> N;
    vector<ll> v, w;
    rep(i, 0, N) {
        ll x, y;
        cin >> x >> y;
        v.pb(x+y);
        w.pb(x-y);
    }
    sort(all(v));
    sort(all(w));
    ans = max(abs(v[sz(v)-1] - v[0]), abs(w[sz(w)-1]-w[0]));
    
    cout << ans << endl;
    return 0;
}



