#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
vvi g;
ll K;
ll N;
ll sum=1;
vb visited;
// dfs return dist1;
void dfs(ll curr,ll p,ll dist1,ll dist2){
    sum=sum*(K-dist1-dist2)%MOD;
    for(auto to:g[curr]){
        if(to==p){
            continue;
        }
        dfs(to,curr,1,dist1);
        dist1++;
    }
}





int main(){
    cin>>N>>K;
    g.resize(N+1);
    visited.assign(N+1,0);
    for(ll i=1;i<N;i++){
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0,0);   // currNOde parent dist1 dist2
    out(sum);
    return 0;
}
