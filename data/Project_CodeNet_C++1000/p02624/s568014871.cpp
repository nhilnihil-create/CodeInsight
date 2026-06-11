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
using namespace std; const int N=10000010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch-'0'), ch=getchar();
    return s*w;
}
void print(int x) { if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int d[N],res,book[N],pri[N/10],mi[N],cnt;
signed main()
{
    int n=read();
    d[1]=1; res=1;
    for(ri int i=2;i<=n;i++)
    {
        if(!book[i]) pri[++cnt]=i, mi[i]=1, d[i]=2;
        for(ri int j=1;j<=cnt&&i*pri[j]<=n;j++)
        {
            book[i*pri[j]]=1;
            if(i%pri[j]) d[i*pri[j]]=d[i]*2, mi[i*pri[j]]=1;
            else
            {
                mi[i*pri[j]]=mi[i]+1;
                d[i*pri[j]]=d[i]/(mi[i]+1)*(mi[i*pri[j]]+1);
                break;
            }
        }
    }
    for(ri int i=2;i<=n;i++) res+=d[i]*i;
    printf("%lld\n",res);
    return 0;
}