#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt", "r", stdin)
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
void read(int& val) { int x = 0; int bz = 1; char c; for (c = getchar(); (c<'0' || c>'9') && c != '-'; c = getchar()); if (c == '-') { bz = -1; c = getchar(); }for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48; val = x * bz; }
const int maxn = 1e2+2;

char mp[maxn][maxn];
int dp[maxn][maxn];
bool vis[maxn][maxn];
int n,m;

void sol(int x,int y,int v){
    dp[x][y]=min(dp[x][y],v);
    int nx=x+1,ny=y;//down
    if(nx<=n&&mp[nx][ny]=='#'&&!vis[nx][ny]) {
        vis[nx][ny]=true;
        sol(nx,ny,v);
    }
    nx=x,ny=y+1;//right
    if(ny<=m&&mp[nx][ny]=='#'&&!vis[nx][ny]) {
        vis[nx][ny]=true;
        sol(nx,ny,v);
    }
}

int main(){
//    op;
    read(n);read(m);
    fo(i,1,n) scanf("%s",mp[i]+1);
    fo(i,0,n+1){
        fo(j,0,m+1) dp[i][j]=dp[i][j]=INF;
    }
    dp[0][1]=dp[1][0]=0;
    fo(i,1,n){
        fo(j,1,m){
            int nw=mp[i][j]=='#';
            //如果我是黑色，那么我就进行翻转
            if(nw==1){
                int mi=min(dp[i-1][j],dp[i][j-1])+1;
                sol(i,j,mi);
                me0(vis);
            }
            else{
                dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }

    printf("%d\n",dp[n][m]);

    return 0;
}