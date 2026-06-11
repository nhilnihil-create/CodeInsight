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
const int N=100000+100;
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

int n,a[200200];
ll L[200200],R[200200];

int main()
{
    n=read();
    rep(i,0,n) a[i]=read();
    if (a[0])
    {
        if ((n==0) && (a[0]==1)) puts("1");
        else puts("-1");
        return 0;
    }
    per(i,n,0)
    {
        L[i]=a[i]+(L[i+1]+1)/2;
        R[i]=a[i]+R[i+1];
    }
    //cout << L[0] << " " << R[0] << endl;
    if (L[0]>1) {puts("-1");return 0;}
    ll ans=1,now=1;
    //rep(i,1,n) cout << R[i] << " ";cout << endl;
    rep(i,1,n)
    {
        now=min(now*2,R[i]);
        ans+=now;
        now-=a[i];
    }
    printf("%lld",ans);
    return 0;
}