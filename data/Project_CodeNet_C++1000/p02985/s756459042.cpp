#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,k,cnt=0;
int head[maxn];
struct node{
    int v,nxt;
}t[2*maxn];
void add(int u,int v){
    t[++cnt].v=v;
    t[cnt].nxt=head[u];
    head[u]=cnt;
}
int dfs(int u,int fa,int m){
    if(m==0)return 0;
    int st=(u==1?k-1:k-2);
    int ans=1;
    for(int x=head[u];x;x=t[x].nxt){
    int v=t[x].v;

    if(v!=fa){
        ans=(1ll*ans*dfs(v,u,st))%mod;
        if(ans==0)return 0;
        st--;
    }

    }
    ans = 1ll*ans*m%mod;
    return ans;
}

int main(){
    scanf("%d%d",&n,&k);

    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }

    printf("%d\n",dfs(1,0,k));

    return 0;
}
