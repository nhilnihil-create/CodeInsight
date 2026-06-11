#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, k, e[N];

void init() 
{
    for (int i=2; i<N; ++i) 
    {
        e[i] = 1;
    }
    for (int i=2; i<N; ++i) 
    {
        if (e[i] == 1) 
        {
            for (int k,j=i+i; j<N; j+=i) 
            {
                k=j / i;
                while (k % i == 0) 
                {
                    k /= i;
                    e[j]++;
                }
            }
        }
    }
}

const int mod = 1000000007;

int pw  (int a, int b, int m) 
{
    if (b==0)return 1;
    int c = pw(a, b/2, m);
    c = 1LL * c * c % m;
    if (b % 2 == 1) 
        c = c * 1LL * a % m;
    return c;
}

int f[N];

int main() 
{
    cin >> n >> k;
    init();
    int ans = 0;
    for (int i=k; i>=1; --i) 
    {
        f[i] = pw(k / i, n, mod);
        for (int j=i+i; j<=k; j+=i) 
        {
            f[i] = (f[i] - f[j] + mod) % mod;
        }
        ans = (ans + f[i] * 1LL * i) % mod;
    }
    cout << ans;
}