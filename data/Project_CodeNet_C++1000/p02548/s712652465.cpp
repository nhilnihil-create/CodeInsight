#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include<bits/stdc++.h>
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i,a,b) for(register int i=a,bbb=b;i<=bbb;++i)
#define repd(i,a,b) for(register int i=a,bbb=b;i>=bbb;--i)
#define reps(s) for(register int i=head[s],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define ce(i,r) i==r?'\n':' '
#define pb push_back 
#define all(x) x.begin(),x.end()
#define gmn(a,b) a=min(a,b)
#define gmx(a,b) a=max(a,b)
#define fi first
#define se second
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;
std::mt19937 rnd(time(0));//std::mt19937_64 rnd(time(0));
typedef long long ll;
typedef double db;
inline int qi(){
    int f=0,fu=1; char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1; c=getchar(); }
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+c-48; c=getchar(); }
    return f*fu;
}
inline ll ql(){
	ll f=0;int fu=1; char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1; c=getchar(); }
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+c-48; c=getchar(); }
    return f*fu;
}
inline ll ceil_div(ll a,ll b){ return (a+b-1)/b; }
//start!
const int MAX_N=2e5+5;
const int mod=998244353;
struct node{ int l,r; }il[MAX_N];
int dp[MAX_N],sum[MAX_N]; 
int main()
{
	int n=qi(),ans=0;	
	repi(i,1,n-1) ans+=(n-1)/i;
	printf("%d\n",ans);
	return 0;
}