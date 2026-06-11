#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(i=a;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortrev(x) sort(all(x),greater<int>())
#define pi 3.1415926535897932384626

typedef pair<int,int> pii;
typedef pair<ll, ll> pl;
typedef vector<int>	vi;
typedef vector<bool> vb;
typedef vector<ll>	vl;
typedef vector<pii>	vpii;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef vector<double> vd;


const int mod = 1000000007;
const int inf = 1000000000;
const int N = 200007, M = N;
ll i,j,cnt,par;
vi vec[N];

ll dfs(ll u , vi& vis) {
    vis[u] = 1;
    ll cnt = 1;
    for(ll v : vec[u]) {
        if(!vis[v]) {
            cnt+=dfs(v , vis);
        }
    }
    return cnt;
}

void solve() {
   ll n,m;
   cin>>n>>m;

   ll x,y;

   for(int i=0;i<m;i++) {
    cin>>x>>y;
    vec[x].pb(y);
    vec[y].pb(x);
   }

   ll ans = 0;
   vi vis(n+1,0);
   for(int i=1;i<=n;i++) {
    if(!vis[i]) ans = max(ans , dfs(i,vis));
   }

   cout<<ans<<"\n";
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}


