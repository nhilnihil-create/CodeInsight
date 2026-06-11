#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 4e18
#define EPS 1e-3
#define PI 3.1415926535897932385
#define display(v) f(v.size())cout << v[i]<<" "
const double h = 1e-6;
const int MAX_  = 200005;
#define all(v) v.begin(),v.end()

inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
ll sqr(ll x)
{
    return x*x;
}
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////
struct graph{
    vi v;
};
graph G[MAX_];
int n,m;
int s,t;

void bfs(){
    int arr[n+1][3];  // vertices , shortest distance modulo
    int nax = 1e8;
    for(int i =0;i<=n;i++){
        arr[i][0] = arr[i][1] = arr[i][2]= nax;
    }
    arr[s][0] = 0;
    queue<pair<int,int> > q;
    q.push({s,0});  // s to t.
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        int from = temp.ff;
        int mo = temp.ss;
        for(int i =0;i<G[from].v.size();i++){
            int to = G[from].v[i];
            int distance = (mo+1)%3;
            if(arr[to][distance]==nax){
                arr[to][distance] = arr[from][mo] + 1;
                q.push({to,distance});
            }
        }
    }
    if(arr[t][0] == nax){
        cout << -1 << "\n";
    }
    else{
        int ans = arr[t][0];
        cout << ans/3 ;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    f(m){
        int x,y;  
        cin>>x>>y;
        G[x].v.pb(y); //directed graph
    }
    cin>>s>>t;
    bfs();
    return 0;
}
    
