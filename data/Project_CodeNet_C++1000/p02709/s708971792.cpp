#include<bits/stdc++.h>
#define pb push_back
#define ef(i,u) for(int i=b[u];i;i=nxt[i])
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,b,a) for(int i=b;i>=a;--i)
#define gcd(a,b) __gcd(a,b)
#define MEM(a,x) memset(a,x,sizeof(a))
#define VI vector<int>
#define PII pair<int,int>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
const int N=2005;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int n;
ll dp[N][N];
PII a[N];
bool cmp(PII x,PII y){
    return x.fi>y.fi;
}
ll cal(int now,int l,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll res=1ll*a[now].fi*abs(a[now].se-l)+cal(now+1,l+1,r);
    res=max(res,1ll*a[now].fi*abs(r-a[now].se)+cal(now+1,l,r-1));
    return dp[l][r]=res;
}
int main(){
    cin>>n;
    int x;
    rep(i,1,n){
        read(x);
        a[i]=PII(x,i);
    }
    sort(a+1,a+1+n,cmp);
    MEM(dp,-1);
    ll ans=cal(1,1,n);
    cout<<ans<<'\n';
	return 0;
}
