#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    if (p == 5 || p == 2)
    {
        ll cnt = 0;
        for (ll j = 0; j < s.length(); j++)
        {
            auto num = s[j] - '0';
            if (num % p == 0)
            {
                cnt += j + 1;
            }
        }

        cout << cnt << endl;
        return 0;
    }

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    vector<ll> mods = {};
    auto mod = 0;
    auto digit_mod = 1;
    for (auto i = 0; i < reversed.length(); i++)
    {
        auto digit = reversed[i] - '0';
        if (i != 0)
        {
            digit_mod = digit_mod * 10 % p;
        }
        mod = (mod + digit_mod * digit) % p;
        mods.push_back(mod);
    }

    reverse(mods.begin(), mods.end());
    map<ll, ll> comb = {};

    for (auto i = 0; i < mods.size(); i++)
    {
        auto m = mods[i];
        if (comb.count(m))
        {
            comb[m] = comb[m] + 1;
        }
        else
        {
            comb[m] = 1;
        }
    }

    ll cnt = 0;
    for (auto value : comb)
    {
        if (value.first == 0)
        {
            cnt += value.second;
        }

        if (value.second > 1)
        {
            cnt += value.second * (value.second - 1) / 2;
        }
    }

    cout << cnt << endl;
    return 0;
}
