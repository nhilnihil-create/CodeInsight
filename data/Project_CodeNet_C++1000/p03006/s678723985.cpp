//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

struct union_find{
    vector<in> par;
    vector<in> depth;
    vector<in> siz;
    in kid;
    union_find(in n) : par(n) , depth(n,0) , siz(n,1){
        rep(i,n) par[i]=i;
        kid=n;
    }
    in find(in x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unite(in x,in y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        kid --;
        siz[x] +=siz[y];
        siz[y] =siz[x];
        if(depth[x]<depth[y]) par[x]=par[y];
        else{
            par[y]=par[x];
            if(depth[x]==depth[y]) depth[x] ++;
        }
    }
    bool same(in x,in y){
        return find(x)==find(y);
    }
    in size(in x){
        return siz[find(x)];
    }
    in kind(){
        return kid;
    }
};

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n;
    cin>>n;
    vector<P> a(n);
    in p,q;
    rep(i,n){
        cin>>p>>q;
        a[i]=P(p,q);
    }
    in ans=n;
    rep(i,n-1)REP(j,i+1,n){
        p=a[j].first-a[i].first;
        q=a[j].second-a[i].second;
        union_find uf(n);
        uf.unite(i,j);
        rep(x,n-1)REP(y,x+1,n){
            if(uf.same(x,y)) continue;
            in np,nq;
            np=a[x].first-a[y].first;
            nq=a[x].second-a[y].second;
            if(np==p && nq==q) uf.unite(x,y);
            else if(p==-np && q==-nq) uf.unite(x,y);
        }
        in cnt=uf.kind();
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/