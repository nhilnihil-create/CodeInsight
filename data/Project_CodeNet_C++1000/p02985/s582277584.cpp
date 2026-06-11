#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define orz 1000000007
using namespace std;
long long n,k;
bool vis[100005];//dfs
vector<int> mp[100005];
queue<int> q;

long long inv[100005]={1,1},fact[100005]={1,1},f[100005]={1,1};

void init()
{//快速计算阶乘的逆元
    int i;
    for(i=2;i<=k;i++){
        fact[i]=fact[i-1]*i%orz;
        f[i]=(orz-orz/i)*f[orz%i]%orz;
        inv[i]=inv[i-1]*f[i]%orz;
    }
}



long long bfs(){
    int i,cur,v;
    long long cnt,ans=1;
    vis[1]=true;
    for(i=0;i<mp[1].size();i++){
        v=mp[1][i];
        q.push(v);
        vis[v]=true;
    }
    cnt=mp[1].size();
    ans=(fact[k]*inv[k-cnt-1])%orz;
    while(!q.empty()){
        cur=q.front();q.pop();
        for(i=0,cnt=0;i<mp[cur].size();i++){
            v=mp[cur][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
                cnt++;
            }
        }
        if(k-2<cnt) return 0;//没有涂色方案 颜色不够
        if(cnt==0) continue;
        ans*=(fact[k-2]*inv[k-2-cnt])%orz;
        ans%=orz;
    }

    return ans;
}

int main(){
    int u,v,maxcnt=0,i;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    init();
    printf("%lld",bfs());
    return 0;
}
