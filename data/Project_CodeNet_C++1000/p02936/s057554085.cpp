#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<ll>> v;
vector<ll> cost;

void dfs(ll nv, ll p=-1){
    for(auto x: v[nv]){
        if(x==p) continue;
        cost[x] += cost[nv];
        dfs(x, nv);
    }
}

int main(){
    ll n, q;   cin >> n >> q;
    v.resize(n), cost.resize(n);
    rep(i, n-1){
        ll a, b;    cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    rep(i, q){
        ll a, c;    cin >> a >> c;
        cost[a-1] += c;
    }
    dfs(0);
    rep(i, n) cout << cost[i] << ' ';
}
