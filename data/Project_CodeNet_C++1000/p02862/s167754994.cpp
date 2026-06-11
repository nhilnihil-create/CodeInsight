#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long int lli;
typedef long long ll;

const int MAX = 1000000;

long long fac[MAX],finv[MAX],inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i-1]*i % mod;
        inv[i] = mod - inv[mod%i]*(mod/i)%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

long long COM(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}


int main()
{
    int x,y; cin >> x >> y;
    if(2*x-y < 0 || (2*x-y)%3 != 0 || 2*y - x < 0 || (2*y - x)%3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int a = (2*x-y)/3;
    int b = (2*y-x)/3;
    COMinit();
    cout << COM(a+b,a) << endl;
    return 0;
}