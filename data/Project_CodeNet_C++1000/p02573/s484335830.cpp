#include<iostream>
#include<numeric>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<tuple>
#include<string>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
using ll = long long;

class DisjoinSet{
    public:
        vector<int> p,r;
        
        DisjoinSet(){}
        DisjoinSet(int size){
            r.resize(size,0);
            p.resize(size,0);
            for(int i=0;i<size;i++) makeSet(i);
        }

        void makeSet(int x){
            p[x]=x;
            r[x]=0;
        }

        bool same(int x,int y){
            return findSet(x)==findSet(y);
        }

        void unite(int x,int y){
            link(findSet(x),findSet(y));
        }

        void link(int x,int y){
            if(r[x]>r[y]) p[y]=x;
            else{
                p[x]=y;
                if(r[x]==r[y]) r[y]++;
            }
        }

        int findSet(int x){
            if(x!=p[x]) p[x]=findSet(p[x]);
            return p[x];
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    map<int,int> k;
    DisjoinSet ds=DisjoinSet(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ds.unite(a,b);
    }
    for(int i=0;i<n;i++){
        int s=ds.findSet(i);
        k[s]++;
    }
    int ans=0;
    for(auto p:k){
        ans=max(ans,p.second);
    }
    cout<<ans<<endl;
}
