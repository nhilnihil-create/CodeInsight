#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
#define show(x) cout << #x << " is " << x << "\n";
typedef vector<ll> vi;
#define fi first
#define se second
const ll inf = INT_MAX;
const ll mod = 1e9 + 7;

void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;

        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

const ll N = 1e5 + 2;
vector<ll> adj[N];
bool visited[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	ll n, m;
	cin>>n>>m;
	ll u, v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].pb(v);
		
	}
	ll s, t;
	cin>>s>>t;
	
	ll dist[n+1][3];
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=3;j++){
	        dist[i][j] = inf;
	    }
	}
	//memset(dist, inf, sizeof(dist));
	
	queue<pair<ll, ll > > q;
	q.push({s, 0});
	dist[s][0] = 0;
	while(!q.empty()){
		pair<ll, ll> temp = q.front();
		q.pop();
		for(auto er : adj[temp.first]){
			int yu = temp.second + 1;
			yu = yu%3;
			
			if(dist[er][yu] == inf){
				dist[er][yu] = dist[temp.first][temp.second] + 1;
				q.push({er, yu});
			}
		}
	}
	ll ans = dist[t][0];
	
	if(ans == inf) ans=-1;
	else ans/=3;
	
	cout<<ans<<"\n";
	return 0;
}
