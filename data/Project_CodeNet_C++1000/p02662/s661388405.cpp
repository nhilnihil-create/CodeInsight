#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long
#define MOD (long long)998244353
#define MAX_S 3001

int fact[MAX_S];
int inv_fact[MAX_S];

int mod_pow(int x, int p)
{
    int res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = res * x % MOD;

        p >>= 1;
        x = x * x % MOD;
    }
    return res;
}

void set_fact()
{
    fact[0] = 1;
    for (int i = 1; i < MAX_S; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[0] = 1;
    for (int i = 1; i < MAX_S; i++)
    {
        inv_fact[i] = mod_pow(fact[i], MOD - 2);
        //cout << inv_fact[i] << endl;
    }
}

int nCr(int n, int r)
{
    return ((fact[n] * inv_fact[r]) % MOD) * inv_fact[n - r] % MOD;
}

signed main()
{
    int N, S;
    cin >> N >> S;

    set_fact();

    //cout << nCr(5, 2) << endl;
    vector<int> data(N);

    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        data[i] = a;
        if (m.find(a) == m.end())
        {
            m[a] = 1;
        }
        else
        {
            m[a]++;
        }
    }

    vector<vector<int>> vvsum(N + 1, vector<int>(S + 1, 0));
    vvsum[0][0] = 1;
    int c = 0;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i <= S; i++)
        {
            vvsum[j + 1][i] += vvsum[j][i] * 2;
            vvsum[j + 1][i] %= MOD;
            if (data[j] + i <= S)
            {
                vvsum[j + 1][i + data[j]] += vvsum[j][i];
                vvsum[j + 1][i + data[j]] %= MOD;
            }
        }
    }

    // for (const auto &[key, value] : m)
    // {
    //     for (int i = 0; i <= S; i++)
    //     {
    //         for (int j = 0; j <= value; j++)
    //         {
    //             int sum = i + key * j;
    //             if (sum > S)
    //                 break;
    //             int mul = 0;
    //             for (int k = j; k <= value; k++)
    //             {
    //                 mul += nCr(value, k) * nCr(k, j) % MOD;
    //                 mul %= MOD;
    //             }
    //             vvsum[c + 1][sum] += vvsum[c][i] * mul % MOD;
    //             vvsum[c + 1][sum] %= MOD;
    //             //cout << value << " " << j << " " << nPr(value, j) << endl;
    //         }
    //     }
    //     c++;
    // }

    // for (vector<int> v : vvsum)
    // {
    //     for (int x : v)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> cheat(S + 1, 0);
    // for (int i = 1; i < (1 << (N)); i++)
    // {
    //     int b = i;
    //     int s = 0;
    //     int mul = 1;
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (b & 1)
    //             s += data[j];
    //         else
    //             mul *= 2;
    //         b >>= 1;
    //     }
    //     if (s <= S)
    //     {
    //         cheat[s] += mul;
    //         cheat[s] %= MOD;
    //     }
    // }
    // for (int x : cheat)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << vvsum[N][S] << endl;
}