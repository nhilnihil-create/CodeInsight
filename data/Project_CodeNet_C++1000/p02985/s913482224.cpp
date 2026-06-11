#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 1e5+5;
const ll modd = 1000000007;
int head[N],to[N<<1],nex[N<<1],cnt;
int fat[N];
void addedge(int u,int v){
    to[++cnt] = v;
    nex[cnt] = head[u];
    head[u] = cnt;
}
ll ans = 1;
int n,k;
void dfs(int x,int fa){
    int timm = -1;
    for(int i=head[x];i;i=nex[i]){
        int v= to[i];
        if(v==fa) continue;
        ++timm;
        //if(timm>2) timm=2;
        ans = (ans * ((ll)k-(fat[v]!=0)-(fat[fat[v]]!=0)-timm) )%modd;
        //cout<<x<<" "<<"time:"<<timm<<endl;
        //cout<<"sub:"<<(k-(fat[v]!=0)-(fat[fat[v]]!=0)-timm)<<endl;
        //cout<<ans<<endl;
        
        dfs(v,x);
    }
}
void dfs1(int x,int fa){
    for(int i=head[x];i;i=nex[i]){
        int v= to[i];
        if(v==fa) continue;
        fat[v] = x;
        dfs1(v,x);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    rep(i,1,n-1){
        int a,b;cin>>a>>b;
        addedge(a,b);addedge(b,a);
    }

    dfs1(1,0);
    // rep(i,1,n){
    //     cout<<"fa"<<i<<" :"<<fat[i]<<endl;
    // }
    ans = k;
    dfs(1,0);
    
    cout<<ans;

}