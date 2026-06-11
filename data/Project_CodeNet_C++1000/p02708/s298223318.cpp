// Gaurav Nuti
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<pll > vll;
#define pb push_back
#define mp make_pair 
#define ar array
#define mod 1000000007
#define F first
#define S second
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define For(i, a, b) for(__typeof (a) i=a; i<=b; i++)
#define inp_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {cin>>a[i];}
#define debug_arr(a,n) {{for(__typeof (n) i=0; i<n; ++i) {cout<<a[i]<<" ";}cout<<"\n";}}
#define INF 1e9 

ll power(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1;
        x = (x*x)%mod; 
    } 
    return res%mod; 
}

ll power_without_mod(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x); 
        y = y>>1;
        x = (x*x); 
    } 
    return res; 
}

bool comparep(pair<ll, ll> i1, pair<ll, ll> i2){
	return (i1.S < i2.S);
} 

ll modInverse(ll a)
{
    return power(a , mod - 2);
}

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> dist;
map<ll,ll> mymap;
ll max_dist = 1;

void bfs(int u1){
    visited[u1] = 1;
    dist[u1] = 1;
    mymap[1] = u1;
    queue<ll> q;
    q.push({u1});
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto i=graph[u].begin();i!=graph[u].end();i++){
            if(!visited[*i]){
                dist[*i] = dist[u] + 1;
                visited[*i] = 1;
                max_dist = max(dist[*i],max_dist);
                mymap[dist[*i]] = *i;
                q.push({*i});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif  
	
    ll t;
    // cin>>t;
    t = 1;
    for(ll z=0;z<t;z++){
        ll n, k;
        cin>>n>>k;
        ll sum = 0;
        for(ll i=k; i<=n;i++){
            sum += ((n+1-i)%mod)*(i%mod) + 1;
            sum %= mod;
            // cout<<i<<" "<<(n+1-i)*i + 1<<"\n";
        }
        cout<<(sum+1)%mod;
    }
}