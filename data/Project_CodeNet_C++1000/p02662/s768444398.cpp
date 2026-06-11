#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const ll mod=998244353;
inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
const int N=3e3+10;
ll dp[N][N];
int a[N],n,s;
void add(ll &x,ll y)
{
    x=(x+y)%mod;
}
int main()
{
    n=read(),s=read();
    rep(i,1,n) a[i]=read();
    dp[0][0]=1;
    rep(i,1,n)
    {
        for(int j=0;j<=s;++j) dp[i][j]=dp[i-1][j]*2%mod;
 
        for(int j=s;j>=a[i];--j){
            add(dp[i][j],dp[i-1][j-a[i]]);
        }
    }
    printf("%lld\n",dp[n][s]);
}