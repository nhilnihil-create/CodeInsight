#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline int read()
{
    char ch=getchar(); int f=1,x=0;
    while (ch<'0' || ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return f*x;
}

const int N=300005;
ll t2[N];
int n,m,cnt[N],s[N],t[N],id[N];

inline void add1(int x,int y) { for (;x<=n;x+=x&-x) t[x]+=y; }

inline void add2(int x,int y) { for (;x<=n;x+=x&-x) t2[x]+=y; }

inline int query1(int x)
{
    int ans=0;
    for (;x;x-=x&-x) ans+=t[x];
    return ans;
}

inline ll query2(int x)
{
    ll ans=0;
    for (;x;x-=x&-x) ans+=t2[x];
    return ans;
}

inline bool check(int c,int mid)
{
    int x=query1(n)-query1(mid-1);
    ll sum=query2(mid-1);
    return sum>=1ll*(c-x)*mid;
}

signed main()
{
    n=read();
    for (int i=1;i<=n;i++) cnt[read()]++;
    for (int i=1;i<=n;i++)
    {
        if (!cnt[i]) continue;
        s[++m]=cnt[i];
    }
    for (int i=1;i<=m;i++)
    {
        add1(s[i],1);
        add2(s[i],s[i]);
    }
    for (int i=1;i<=n;i++)
    {
        int l=0,r=n/i;
        while (l<r)
        {
            int mid=(l+r+1)>>1;
            if (check(i,mid)) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}