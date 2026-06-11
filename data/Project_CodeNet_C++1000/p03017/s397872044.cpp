#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
char s[Maxn];
bool f[Maxn],g[Maxn];
int s1[Maxn],s2[Maxn];
#define modp 998244353
int len,a,b,c,d;
int main()
{
    scanf("%d%d%d%d%d",&len,&a,&b,&c,&d);
    scanf("%s",s+1);
    if (c<d)
    {
        bool check=true;
        memset(f,false,sizeof(f));
        f[b]=true;
        for (int i=b+1;i<=d;i++)
            if (s[i]=='.')
            {
                if (i>1&&f[i-1]) f[i]=true;
                if (i>2&&f[i-2]) f[i]=true;
            }
        if (!f[d]) check=false;
        memset(f,false,sizeof(f));
        f[a]=true;
        for (int i=a+1;i<=c;i++)
            if (s[i]=='.')
            {
                if (i>1&&f[i-1]) f[i]=true;
                if (i>2&&f[i-2]) f[i]=true;
            }
        if (!f[c]) check=false;
        if (check) printf("Yes\n"); else printf("No\n");
    } else
    {
        memset(f,false,sizeof(f));
        f[b]=true;
        for (int i=b+1;i<=d;i++)
            if (s[i]=='.')
            {
                if (i>1&&f[i-1]) f[i]=true;
                if (i>2&&f[i-2]) f[i]=true;
            }
        memset(g,false,sizeof(g));
        g[d]=true;
        for (int i=d-1;i>=b;i--)
            if (s[i]=='.')
            {
                if (g[i+1]) g[i]=true;
                if (g[i+2]) g[i]=true;
            }
        memset(s1,0,sizeof(s1));
        s1[a]=1;
        for (int i=a+1;i<=c;i++)
            if (s[i]=='.')
            {
                if (i>1) s1[i]=(s1[i]+s1[i-1])%modp;
                if (i>2) s1[i]=(s1[i]+s1[i-2])%modp;
            }
        memset(s2,0,sizeof(s2));
        s2[c]=1;
        for (int i=c-1;i>=a;i--)
            if (s[i]=='.')
            {
                s2[i]=(s2[i]+s2[i+1])%modp;
                s2[i]=(s2[i]+s2[i+2])%modp;
            }
        bool check=false;
        for (int i=b;i<=d;i++)
            if (f[i]&&g[i]&&((1LL*s1[i]*s2[i])%modp!=s1[c])) check=true;
        if (check) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}