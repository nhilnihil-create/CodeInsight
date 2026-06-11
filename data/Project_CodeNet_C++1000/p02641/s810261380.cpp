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
using namespace std; const int N=2000010, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch-'0'), ch=getchar();
    return s*w;
}
void print(int x) { if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int X,n,a[N],book[N];
signed main()
{
    X=read()+100, n=read();
    for(ri int i=1;i<=n;i++) a[i]=read()+100, book[a[i]]=1;
    int mi=1e9, g=0;
    for(ri int i=0;i<=300;i++)
    {
        if(book[i]) continue;
        if(abs(i-X)<mi) mi=abs(i-X), g=i;
    }
    printf("%lld\n",g-100);
    return 0;
}