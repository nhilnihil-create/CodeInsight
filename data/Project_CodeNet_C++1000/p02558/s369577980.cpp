//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

struct union_find{
    vector<int> par;
    vector<int> depth;
    vector<int> siz;
    int kid;

    union_find(int n) : par(n) , depth(n,0) , siz(n,1){
        rep(i,n) par[i]=i;
        kid=n;
    }

    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }

    void unite(int x,int y){
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

    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return siz[find(x)];
    }
    int kind(){
        return kid;
    }
};

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,q;
    cin>>n>>q;
    union_find uf(n);
    int x,y,z;
    rep(i,q){
        cin>>x>>y>>z;
        if(x) cout<<uf.same(y,z)<<endl;
        else uf.unite(y,z);
    }
}/*
./problem.exe
*/