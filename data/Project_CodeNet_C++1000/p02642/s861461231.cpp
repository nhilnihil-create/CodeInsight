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
using namespace std; const int N=200010, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch-'0'), ch=getchar();
    return s*w;
}
void print(int x) { if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int n,a[N],book[N*10],res;
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read(), book[a[i]]++;
    for(ri int i=1;i<=n;i++)
    {
        if(a[i]==1&&book[a[i]]==1) { res++; continue; }
        int qwq=1;
        for(ri int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j) continue;
            int x=a[i];
            if(book[j] || (x/j!=x && book[x/j]) || (x/j==x && book[x/j]>1)) { qwq=0; break; }
        }
        res+=qwq;
    }
    printf("%lld\n",res);
    return 0;
}