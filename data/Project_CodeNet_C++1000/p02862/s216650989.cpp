#include <iostream>
#include <vector>

using namespace std;

int n, m;
int mod = 1000000007;
vector<long long> fac, inv, finv;

void combinit()
{
    fac.resize(n + m + 1);
    inv.resize(n + m + 1);
    finv.resize(n + m + 1);

    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < n + m + 1; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
    
}

long long combination(int n, int k){
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(int argc, char const *argv[])
{
    long long X, Y;
    cin >> X >> Y;
    int ans;
    if ((X + Y) % 3 == 0)
    {
        m = (2 * Y - X) / 3;
        n = Y - 2 * m;
        if (n < 0 || m < 0)
        {
            ans = 0;
            cout << ans << endl;
            return 0;
        }
        combinit();
        ans = (int)combination(n + m, n);
    }else
    {
        ans = 0;
    }
    
    cout << ans << endl;
    
    return 0;
}