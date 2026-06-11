// AtCoder Beginner Contest 129 - Problem E: Sum Equals Xor (https://atcoder.jp/contests/abc129/tasks/abc129_e) 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD { 1000000007 };

const int MAX { 100010 };

ll dp[MAX][2];

ll fast_exp(ll a, ll n)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        n >>= 1;
    }

    return res;
}

ll solve(const string& L)
{
    int N = (int) L.size();
    dp[1][0] = 1;       // A + B < L
    dp[1][1] = 2;       // A + B == L

    for (int i = 2; i <= N; ++i)
    {
        // Duas possíbilidades para o último dígito ser 1 (concatenar (1, 0) ou (1, 0) em cada
        // termo, só uma (concatenar (0, 0)) se o último dígito é zero
        dp[i][1] = (dp[i - 1][1] * (L[i - 1] == '1' ? 2 : 1)) % MOD;

        // Transição:
        //      1. Manter o que já estava funcionado
        //      2. Concatenar (1, 0) ou (1, 0) ao final de cada que já funcionava
        //      3. Se o próximo dígito é '1', os prefixos p iguais ao anterior geram novas válidas
        //         menores que L quando acrescidos de um zero no final
        //         e (0, p | 0)           
        dp[i][0] = (3*dp[i - 1][0] + (L[i - 1] == '1' ?  dp[i - 1][1] : 0)) % MOD;
    }

#ifdef DEBUG
    for (int i = 1; i <= N; ++i)
    {
        cout << "dp[" << i << "][" << 0 << "] = " << dp[i][0] << endl;
        cout << "dp[" << i << "][" << 1 << "] = " << dp[i][1] << endl;
    }
#endif
/*    
    int N = (int) L.size();
    ll ans = 2;

    for (auto c : L)
    {
        N--;

        if (c == '1')
            ans = (ans + fast_exp(3, N)) % MOD;
    }
*/

    ll ans = (dp[N][0] + dp[N][1]) % MOD;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    string L;
    cin >> L;

    auto ans = solve(L);

    cout << ans << '\n';

    return 0;
}
