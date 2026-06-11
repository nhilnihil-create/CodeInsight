#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

vector<ll> solve(int N, const vector<ll>& xs)
{
    map<ll, ll> hs;

    for (auto x : xs)
        ++hs[x];

    ll ways = 0;
    
    for (auto p : hs)
    {
        auto c = p.second;

        ways += c*(c - 1)/2;
    }

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i)
    {
        auto c = hs[xs[i]];

        ans[i] = ways - (c*(c - 1)/2) + (c - 1)*(c - 2)/2;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    for (auto x : ans)
        cout << x << endl;

    return 0;
}
