#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

vector<long long> enum_divisors(long long N)
{
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n, ans = 10000000000000;
    cin >> n;

    const auto &res = enum_divisors(n);

    rep(i, res.size())
    {
        if (ans > res[i] + n / res[i])
            ans = res[i] + n / res[i];
    }
    // for (ll i = 0; i < n / 2; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         if (ans > i + n / i)
    //             ans = i + n / i;
    //         else
    //             break;
    //     }
    // }

    cout << ans - 2 << endl;
    return 0;
}