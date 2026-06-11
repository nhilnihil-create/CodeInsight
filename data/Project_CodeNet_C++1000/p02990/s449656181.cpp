#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 2050 };
const ll MOD { 1000000007 };

ll binom[MAX][MAX];
void precomp()
{
    binom[0][0] = 1;

    for (int n = 1; n < MAX; ++n)
    {
        binom[n][0] = binom[n][n] = 1;

        for (int m = 1; m < n; ++m)
            binom[n][m] = (binom[n - 1][m] + binom[n - 1][m - 1]) % MOD;
    }
}

vector<int> solve(int N, int K)
{
    vector<int> ans(K);

    for (int i = 1; i <= K; ++i)
    {
//cout << "i = " << i << endl;
//cout << "bin[" << K - 1 << "][" << i - 1 << "] = " << binom[K - 1][i - 1] << endl;
//cout << "bin[" << N - K + 2 << "][" << i + 1 << "] = " << binom[N - K + 1][i] << endl;
        ans[i - 1] = (binom[K - 1][i - 1] * binom[N - K + 1][i]) % MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    precomp();

    int N, K;
    cin >> N >> K;

    auto ans = solve(N, K);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
