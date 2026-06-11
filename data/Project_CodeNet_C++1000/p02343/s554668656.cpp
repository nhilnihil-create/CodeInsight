#include<bits/stdc++.h>
#define LL long long
#define rep(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
static const LL INF = 1LL<<61LL;
static const int MAX_N = 10000;
typedef pair<int,int> PII;

int par[MAX_N];
int rank[MAX_N];
int n,q;
int com,x,y;

class UF{
    public:
        void init(int n){
            rep(i,n){
                par[i]=i;
                rank[i]=0;
            }
        }

        int find(int x){
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }

        void unite(int x,int y){
            x=find(x);
            y=find(y);
            if(x==y)return;
            if(rank[x]<rank[y])par[x]=y;
            else {
                par[y]=x;
                if(rank[x]==rank[y])rank[x]++;
            }
        }

        bool same(int x,int y){
            return find(x)==find(y);
        }
};
int main(){
    UF uf;
    cin>>n>>q;
    uf.init(n);
    rep(i,q){
        cin>>com>>x>>y;
        if(com==0)uf.unite(x,y);
        else cout<<uf.same(x,y)<<endl;
    }
    return 0;
}