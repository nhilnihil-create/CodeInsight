#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<pair<ll, ll>> prime_factorize(ll N)
{
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; a++)
    {
        if (N % a != 0)
        {
            res.push_back({a, 0});
            continue;
        }
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1)
    {
        res.push_back({N, 1});
    }
    return res;
}

int main()
{
    ll A, B;
    cin >> A >> B;

    vector<pair<ll, ll>> prime_factors_a = prime_factorize(A);
    vector<pair<ll, ll>> prime_factors_b = prime_factorize(B);

    ll ans = 1;
    for (int i = 0; i < min(prime_factors_a.size(), prime_factors_b.size()); i++)
    {
        auto a = prime_factors_a.at(i);
        auto b = prime_factors_b.at(i);
        if (a.first == b.first && a.second > 0 && b.second > 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}