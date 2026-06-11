#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
#define endl "\n"
struct dsu{
    int g[N];
    void init(){for(int i=0;i<=N;i++)g[i]=i;}
    int find(int x){return x==g[x]?x:g[x]=find(g[x]);}
    void uni(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu!=pv)g[pu]=pv;
    }
}dis;
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n,q;cin>>n>>q;
    dis.init();
    while(q--){
        int mode;cin>>mode;
        int u,v;cin>>u>>v;
        if(mode==0){
            dis.uni(u,v);
        }
        else{
            if(dis.find(u)==dis.find(v))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}
