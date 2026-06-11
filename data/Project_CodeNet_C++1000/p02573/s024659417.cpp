#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T > using oset = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
// find_by_order(k) (k+1)th largest element
// order_of_key(k) no of elements <=k

typedef long long ll;
typedef long double ld;
#define endl '\n'
#define rep(i,n)  for(ll i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define ff first
#define ss second
#define pb push_back
typedef vector<ll> vll;
typedef vector<pair<ll,ll>> vpl;
const ld PI = 4*atan((ld)1);
const ll INF = LLONG_MAX;
const ll mod = 1e9+7;

const ll N = 2e5+5;
vector<ll> g[N];
vector<bool> vis(N,false);
ll cnt=0;
void dfs(ll u){
    vis[u] =1;
    cnt++;
    trav(v,g[u]){
        if(!vis[v]){
            // cnt++;
            dfs(v);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll tt=1;
        // cin >> tt;
    repA(qq,1,tt){
        ll n,m; cin >> n >> m;
        rep(i,m){
            ll x,y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        ll ans =0;
        vll len;
        repA(i,1,n){
            if(!vis[i]){
                cnt=0;
                dfs(i);
                len.pb(cnt);
            }
        }
        sort(all(len));
        ans = len[0];

        // cout<< len[0] <<" ";
        repA(i,1,sz(len)-1){
            // cout << len[i] << " ";
            ans += len[i]-len[i-1];
        }
        // cout << endl;
        cout << ans;
    }
}
