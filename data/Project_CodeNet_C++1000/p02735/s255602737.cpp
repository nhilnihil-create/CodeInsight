#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head


const int N = 1e3+10;
int n,m,clk,dp[N][N],vis[N][N];
char s[N][N];
void chkmin(int &a, int b) {a>b?a=b:0;}
queue<pii> q;
int main() {
	scanf("%d%d", &n, &m);
	REP(i,1,n) scanf("%s",s[i]+1);
	memset(dp,0x3f,sizeof dp);
	dp[0][1] = 0;
	REP(i,1,n) REP(j,1,m) {
		if (s[i][j]=='.') {
			dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
		}
		else { 
			q.push(pii(i,j)),++clk;
			while (q.size()) {
				pii u = q.front(); q.pop();
				int x=u.x,y=u.y;
				if (vis[x][y]==clk) continue;
				vis[x][y] = clk;
				chkmin(dp[i][j],min(dp[x-1][y],dp[x][y-1])+1);
				if (s[x-1][y]=='#') q.push(pii(x-1,y));
				if (s[x][y-1]=='#') q.push(pii(x,y-1));
			}
		}
	}
	printf("%d\n", dp[n][m]);
}







