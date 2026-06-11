#include<bits/stdc++.h>
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;

typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 3e5+20;
const int inf = 0x3f3f3f3f;
const int modd = 1e9+7;

inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
template <class T> inline void sc(T &x){char c;x=0;while((c=getchar())<'0');while(c>='0'&&c<='9')x=x*10+(c-48),c=getchar();}
inline ll gcd(ll a,ll b){ return b==0? a: gcd(b,a%b); }
inline ll exgcd(ll a,ll b,ll &x,ll &y){ll d; (b==0? (x=1,y=0,d=a): (d=exgcd(b,a%b,y,x),y-=a/b*x)); return d;}
inline ll qpow(ll a,ll n){ll sum=1;while(n){if(n&1)sum=sum*a%modd;a=a*a%modd;n>>=1;}return sum;}
inline ll qmul(ll a,ll n){ll sum=0;while(n){if(n&1)sum=(sum+a)%modd;a=(a+a)%modd;n>>=1;}return sum;}
inline ll inv(ll a) {return qpow(a,modd-2);}

int dp[105][105];
char mp[105][105]; 
int n,m;

int dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	//cout<<x<<" "<<y<<endl;
	if(x==n) dp[x][y]=dfs(x,y+1)+(mp[x][y]!=mp[x][y+1]&&mp[x][y]=='#');
	else if(y==m) dp[x][y]=dfs(x+1,y)+(mp[x][y]!=mp[x+1][y]&&mp[x][y]=='#');
	else dp[x][y]=min( (mp[x][y]!=mp[x+1][y]&&mp[x][y]=='#')+dfs(x+1,y) , (mp[x][y]!=mp[x][y+1]&&mp[x][y]=='#')+dfs(x,y+1) );
	return dp[x][y];
} 

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	dp[n][m]=(mp[n][m]=='#');
	dfs(1,1);
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j]," \n"[j==m]);
	printf("%d\n",dp[1][1]);
}

