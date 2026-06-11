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
const int N=1000000+100;
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

int n,a[N],fac[N],pw[N];
char s[N];

int calc(int n,int m)
{
    int tmp=fac[n]-fac[m]-fac[n-m];
    return tmp;
}

int main()
{
    n=read();
    scanf("%s",s+1);
    rep(i,1,n) a[i]=s[i]-'1';
    rep(i,1,n)
    {
        int x=i;
        while (x%2==0) {x/=2;pw[i]++;}
    }
    int ok=1;
    rep(i,1,n) 
        if (a[i]==1) {ok=0;break;}
    if (ok)
    {
        rep(i,1,n) a[i]/=2;
    }
    //rep(i,1,n) cout << pw[i] <<" ";cout << endl;
    rep(i,1,n) fac[i]=fac[i-1]+pw[i];
    int ans=0;
    rep(i,1,n)
    {
        int odd=calc(n-1,i-1);
        if ((!odd) && (a[i]&1)) ans^=1;
    }
    if (ok) ans*=2;
    printf("%d\n",ans);
    return 0;
}