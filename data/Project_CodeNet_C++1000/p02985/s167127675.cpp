#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef string str;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define pb(x)                       push_back(x)
#define pf(x)                       push_front(x)
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll ans = 1 , n , k , mark[MAXN] , h[MAXN];
vector <ll> adj[MAXN];

void dfs(ll v , ll bro){

    ll son = 0;
    mark[v] = 1;
    ans = (ans * (k - min(h[v] , 2LL) - bro)) % MOD;
    for(auto u: adj[v]){
        if(!mark[u]){
            h[u] = h[v] + 1;
            dfs(u , son);
            son ++;
        }
    }

}

int main(){

    cin >> n >> k;
    for(int i = 1; i < n; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    h[1] = 0;
    dfs(1 , 0);
    cout << ans;

}
