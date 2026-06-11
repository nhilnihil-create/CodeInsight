#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 200005
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
struct Edge
{
	int to,nxt;
}edge[2*maxn];
int K,cnt,head[maxn];
ll col[maxn];
const ll mod=1e9+7;
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
	return;
}
void DFS(int u,int fa,int dep)
{
    if(dep==1){
        int cnt=0;
        for(int k=head[u];k!=-1;k=edge[k].nxt){
            int v=edge[k].to;
            if(v==fa) continue;
            //printf("v=%d\n",v);
            cnt++;
            //printf("cnt=%d\n",cnt);
            col[v]=(ll)K-cnt;
            DFS(v,u,dep+1);
        }
    }
    else{
        int cnt=0;
        for(int k=head[u];k!=-1;k=edge[k].nxt){
            int v=edge[k].to;
            if(v==fa) continue;
            cnt++;
            col[v]=(ll)K-1-cnt;
            DFS(v,u,dep+1);
        }
    }
    return;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n=read();
    K=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n-1;i++){
        int u=read(),v=read();
        addedge(u,v);
        addedge(v,u);
    }
    col[1]=(ll)K;
    DFS(1,0,1);
    //for(int i=1;i<=n;i++) printf("%lld ",col[i]);
    //cout<<endl;
    ll ans=1LL;
    for(int i=1;i<=n;i++) ans=((ans%mod)*(col[i]%mod)%mod);
    cout<<ans<<endl;
    return 0;
}
