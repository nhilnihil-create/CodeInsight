#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <bitset>
#define ri register
#define inf 0x7fffffff
#define E (1)
#define mk make_pair
#define int long long
//#define double long double
using namespace std; const int N=400010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch-'0'), ch=getchar();
    return s*w;
}
void print(int x) { if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int n,m,k,a[N],b[N];
signed main()
{
    n=read(), m=read(), k=read();
    int res=0;
    for(ri int i=1;i<=n;i++) a[i]=read(), a[i]+=a[i-1];
    for(ri int i=1;i<=m;i++) b[i]=read(), b[i]+=b[i-1];
    for(ri int i=0;i<=n;i++)
    {
        if(a[i]>k) break;
        int p=upper_bound(b+1,b+1+m,k-a[i])-b;
        res=max(res,i+p-1);
    }
    printf("%lld\n",res);
    return 0;
}