#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define ins insert

#define debug(a) cerr<<(a)<<endl
#define dbrep(a,n) rep(_i,n) cerr<<(a[_i])<<" "; cerr<<endl
#define dbrep2(a,n,m) rep(_i,n){rep(_j,m) cerr<<(a[_i][_j])<<" "; cerr<<endl;}

using namespace std;

template<class A, class B>
ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}
template<class A, class B>
istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}

//-------------------------------------------------
//--Union Find tree
//-------------------------------------------------
class UnionFind
{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
public:
    UnionFind(int n):par(n),rank(n),sz(n){
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return;
        if (rank[rx]<rank[ry]){
            par[rx] = par[ry];
            sz[ry] += sz[rx];
        }else{
            par[ry] = par[rx];
            sz[rx] += sz[ry];
            if (rank[rx]==rank[ry]) rank[rx]++;
        }
    }
    int size(int x){
        return sz[root(x)];
    }
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin>>N>>Q;
    UnionFind uf(N);
    while(Q--){
        int t,u,v; cin>>t>>u>>v;
        if (t==1){
            cout<<uf.same(u,v)<<"\n";
        }else{
            uf.unite(u,v);
        }
    }
    return 0;
}
