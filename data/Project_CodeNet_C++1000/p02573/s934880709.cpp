#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)


struct UnionFind {
    vector<int>pre,sz;
    UnionFind(int n) {
        sz=vector<int>(n,1);
        pre=vector<int>(n);
        for(int i=0;i<n;i++)pre[i]=i;
    }
    int find(int x) {
        if(x!=pre[x])pre[x]=find(pre[x]);
        return pre[x];
    }
    bool unite(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y)return false;
        if(x>y)swap(x,y);
        pre[y]=x,sz[x]+=sz[y];
        return true;
    }
    int maxsz(){
        int ans=0;
        for(auto it:sz)ans=max(ans,it);
        return ans;
    }
};

void solve() 
{
    int n,m;cin>>n>>m;
    UnionFind UF(n);
    REP(i,m){
        int a,b;cin>>a>>b;a--;b--;
        UF.unite(a,b);
    }
    cout<<UF.maxsz()<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}