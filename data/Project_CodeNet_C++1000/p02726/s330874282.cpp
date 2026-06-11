#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


struct edge{
    ll to,cost;
};
ll n;
vector<edge>  G[100010];
ll d[100010];

void  dijkstra(int s){
    priority_queue<pll,vector<pll>,greater<pll>> que;
    fill(d,d+n,LLINF);
    d[s]=0;
    que.push(pll(0,s));

    while(!que.empty()){
        pll p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    } 
}


void solve(){
    ll x,y;
    cin>>n>>x>>y;
    ll ans[200010]={};
    rep(i,n){
        G[i].pb({i+1,1});
        G[i+1].pb({i,1});
    }
    G[x-1].pb({y-1,1});
    G[y-1].pb({x-1,1});
    rep(i,n){
        dijkstra(i);
        rep2(j,i+1,n){
            // if(d[j]==LLINF) cout<<i<<" "<<j<<endl;
            if(d[j]<LLINF)ans[d[j]]++;
        }
    }
    rep2(i,1,n){
        cout<<ans[i]<<endl;
    }
}



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    solve(); 


    return 0;
}
