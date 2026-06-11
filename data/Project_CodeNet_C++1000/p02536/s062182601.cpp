//_nebula_
#include<bits/stdc++.h>
using namespace std;
#define int long  long
#define double long double
int t;
const int M=1e9+7;
const int inf=INT64_MAX;
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int min(int a,int b,int c){
    return min(a,min(b,c));
}
int fspow(int x,int y){
    int ans;
    if(y==0) return 1;
    ans=fspow(x, y/2);
    if(y%2==0) return ((ans*ans)%M);
    return (x*((ans*ans)%M))%M;
}
int gcd(int x,int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(x%y,y);
}
int p2(int x){
    int ans=0;
    while(x>1){
        ans++;
        x/=2;
    }
    return ans;
}
vector<int>grp[100005];
bool vis[100005];
void dfs(int s){
    if(vis[s]) return;
    vis[s]=1;
    for(auto i:grp[s]) dfs(i);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t=1;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   //  cin>>t;
    //int tmp=t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            grp[u].push_back(v);
            grp[v].push_back(u);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            ans++;
            dfs(i);
        }
        cout<<ans-1<<"\n";
    }
}
