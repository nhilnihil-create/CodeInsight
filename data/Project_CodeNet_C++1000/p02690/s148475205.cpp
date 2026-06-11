#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define mk make_pair

template <class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;

/*
    if you have any question about any part of my code,
    please don't shy to ask anytime :)
*/

const ll MOD = 1e18 + 7;
ll poww(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll sq = poww(b, p / 2);

    sq = (sq * sq) % MOD;

    if (p % 2 == 1)
    {
        sq = (sq * b) % MOD;
    }

    return sq;
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = -1000; i <= 1000; i++)
    {
        for (ll j = -1000; j <= 1000; j++)
        {
            ll a = i*i*i*i*i;
            ll b = j*j*j*j*j;
            if (a - b == n)
            {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ll t;
    // cin >> t;

    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}