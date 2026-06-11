#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}

const int MAXN=1000002;
long long prime[MAXN],pricnt,ans,a,b,kc[MAXN],kccnt,gys[MAXN],gyscnt;
bool npri[MAXN];

inline void init()
{
    for (long long i = 2; i < 1000000ll; ++i)
    {
        if(!npri[i]) prime[++pricnt] = i;
        for (long long j = 1; j <= pricnt && i * prime[j] < 1000000ll; ++j)
        {
            npri[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    init();
    read(a);
    read(b);
    for (int i=1;i<=pricnt;++i)
    {
        if(a%prime[i]==0 && b%prime[i]==0) ++ans;
        while(a%prime[i]==0) a/=prime[i];
        while(b%prime[i]==0) b/=prime[i];
    }
    if(a!=1&&a==b) ans+=2;
    else ans+=1;
    printf("%lld",ans);
    return 0;
}