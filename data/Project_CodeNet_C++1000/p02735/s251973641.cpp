#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=100+100;
const db pi=acos(-1.0);
#define lowbit(x) ((x)&(-x))
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

inline ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int n,m,f[N][N],col[N][N];
char s[N];

int main()
{
    n=read();m=read();
    rep(i,1,n)
    {
        scanf("%s",s+1);
        rep(j,1,m) col[i][j]=(s[j]=='#');
    }
    memset(f,0x3f,sizeof(f));
    f[1][1]=col[1][1];
    rep(i,1,n) rep(j,1,m)
    {
        if ((i==1) && (j==1)) continue;
        if (i>1)
        {
            int tmp=f[i-1][j];
            if ((!col[i-1][j]) && (col[i][j])) tmp++;
            f[i][j]=min(f[i][j],tmp);
        }
        if (j>1)
        {
            int tmp=f[i][j-1];
            if ((!col[i][j-1]) && (col[i][j])) tmp++;
            f[i][j]=min(tmp,f[i][j]);
        }
    }
    printf("%d",f[n][m]);
    return 0;
}