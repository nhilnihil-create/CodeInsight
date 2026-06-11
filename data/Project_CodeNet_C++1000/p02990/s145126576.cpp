#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,r) for(int i=(l);i<=(r);i++)
typedef long long LL;
const int maxn=2e5+5;
const int p=1e9+7;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
 
LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}
 
LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m=n-k;
    printf("%d\n",m+1);
    for(int i=2;i<=k;i++)
    {
        int cnt=m-i+1;
        LL ans;
        ans=(Lucas(k-1,i-1)*Lucas(cnt+i,i))%p;
        printf("%lld\n",ans);
    }
}