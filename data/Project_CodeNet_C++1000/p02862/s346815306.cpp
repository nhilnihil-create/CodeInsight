#include <iostream>
#include <vector>

const unsigned long long int MOD = 1000000007;

/* 繰り返し二乗法 */
unsigned long long int mod_repeat_squaring(int n, int p, int mod)
{
    if (p == 0)
    {
        return 1;
    }
    if (p & 1)
    {
        return (n % mod) * mod_repeat_squaring(n, p - 1, mod) % mod;
    }
    else
    {
        return (mod_repeat_squaring(n, p / 2, mod) % mod) * mod_repeat_squaring(n, p / 2, mod) % mod;
    }
}

unsigned long long int mod_comb(int n, int r, int mod)
{
    std::vector<unsigned long long int> fact(n + 1), fact_inv(n + 1);
    
    // 階乗の計算
    fact[0] = 1; //初期値fact[0]からfact[n]まで求めていく
    for (int i = 0; i < n; i++)
    {
        fact[i + 1] = fact[i] * (i + 1) % mod;
    }
    
    // 逆元の計算
    fact_inv[n] = mod_repeat_squaring(fact[n], mod - 2, mod) % mod; //初期値fact_inv[n]からfact_inv[0]まで求めていく
    for (int i = n - 1; i >= 0; i--)
    {
        fact_inv[i] = (fact_inv[i + 1] % mod) * (i + 1) % mod;
    }
    
    return ((fact[n] % mod) * fact_inv[r] % mod) * fact_inv[n - r] % mod;
}

int main() {
    int x, y;
    std::cin >> x >> y;

    if ((x + y) % 3 != 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int n = (- x + 2 * y) / 3;
    int m = (2 * x - y) / 3;

    if (n < 0 || m < 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    if (n + m == 0 || n == 0)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    
    std::cout << mod_comb(n + m, n, MOD) << std::endl;

    return 0;
}