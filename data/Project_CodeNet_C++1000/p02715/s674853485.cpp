#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int N = 1e5+7,MOD = 1e9+7;
typedef long long ll;

int phi[N],primes[N],cnt;
bool st[N];
int qpow(int a,int b)
{
    int res = 1 % MOD;
    while(b)
    {
        if(b & 1)   res = ((ll)res * a) % MOD;
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}
void init(int N)
{
    phi[1] = 1;
    for(int i = 2;i <= N;++i)
    {
        if(!st[i])  primes[cnt++] = i,phi[i] = i - 1;
        for(int j = 0;j < cnt && primes[j] * i <= N;++j)
        {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)
            {
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = (primes[j] - 1) * phi[i];
        }
    }
}
void add(int &x,int y) 
{
    x+=y;
    if(x>=MOD) x-=MOD;
}
signed main()
{
    init(N - 1);
    int n,k;scanf("%d%d",&n,&k);
    int res = 0;
    for(int i = 1;i <= k;++i)
        add(res,1LL*qpow(k/i,n)*phi[i]%MOD);
    printf("%d",res);
    return 0;
}
