#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
#define mod 1000000007
class DSU{
    ll * rank, * parent, n;
public:
    DSU(ll n){
        rank=new ll[n];
        parent=new ll[n];
        this->n=n;
        makeset();
    }
    void makeset(){
        for(ll i=0;i<n;i++){
            parent[i]=i;
        }
    }
    ll find(ll x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void Union(ll x, ll y){
        ll xset=find(x);
        ll yset=find(y);
        if(xset==yset){
            return;
        }
        if(rank[xset]<rank[yset]){
            parent[xset]=yset;
        }
        else if(rank[xset]>rank[yset]){
            parent[yset]=xset;
        }
        else{
            parent[xset]=parent[yset];
            rank[yset]++;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    DSU dsu(n);
    REP(i,m){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        dsu.Union(u,v);
    }
    set<ll> s;
    REP(i,n){
        s.insert(dsu.find(i));
    }
    cout<<s.size()-1<<endl;
}
