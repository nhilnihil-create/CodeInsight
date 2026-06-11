#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define INF 0x3f3f3f3f
#define lowbit(x) x & -x
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=5e3+5;
int p[N],c[N];
int vis[N];
ll sum[N],maxx;

ll check(int x,int k){
    memset(vis,0,sizeof vis);
    int cnt=0;
    while(!vis[x]){
        vis[x]=1;
        sum[++cnt]=c[p[x]];
        x=p[x];
    }
    ll maxxsum=sum[1],ans=0;
    for(int i=2;i<=cnt;i++){
        sum[i]+=sum[i-1];
        maxxsum=max(maxxsum,sum[i]);
    }
    if(k>cnt){
        if(sum[cnt]<=0){
            return maxxsum;
        }
        ll tmp=sum[cnt]*(k/cnt-1);
        int cntt=k%cnt+cnt;
        for(int i=1;i<=cntt;i++){
            if(i>cnt)
                ans=max(ans,sum[i-cnt]+sum[cnt]);
            else
                ans=max(ans,sum[i]);
        }
        return max(maxxsum,ans+tmp);
    }
    ans=-1e18;
    for(int i=1;i<=k;i++){
        ans=max(ans,sum[i]);
    }
    return ans;
    
}

int main(){
#ifdef Mizp
    freopen("in.txt","r",stdin);
#endif
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    maxx=-1e18;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,check(i,k));
    }
    printf("%lld\n",maxx);
    return 0;
}
