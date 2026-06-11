#include <bits/stdc++.h>
#define ri register
//#define int long long
#define E (n+1)
using namespace std; const int N=1000010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],res,book[N];
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    res=a[1];
    for(ri int i=2;i<=n;i++) res=__gcd(res,a[i]);
    int flg=1;
    for(ri int i=1;i<=n;i++)
    {
        if(!flg) break;
        int x=a[i];
        for(ri int j=2;j*j<=x;j++)
        {
            if(x%j) continue;
            while(x%j==0) x/=j;
            if(book[j]) { flg=0; break; }
            book[j]=1;
        }
        if(x>1)
        {
            if(book[x]) { flg=0; break; }
            book[x]=1;
        }
    }
    if(flg) puts("pairwise coprime");
    else if(res==1) puts("setwise coprime");
    else puts("not coprime");
    return 0;
}