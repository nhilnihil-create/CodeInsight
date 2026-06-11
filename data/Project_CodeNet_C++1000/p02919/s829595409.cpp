#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(int N, const vector<int>& xs)
{
    vector<int> is(N + 1);

    for (int i = 0; i < N; ++i)
        is[xs[i]] = i + 1;

    multiset<int> S;

    S.insert(0);
    S.insert(0);
    S.insert(N + 1);
    S.insert(N + 1);

    ll ans = 0;

    for (int n = N; n > 0; --n)
    {
        ll i = is[n];
        auto it = S.upper_bound(i);

        ll x = *(--it);
        ll w = *(--it);

        auto jt = S.upper_bound(i);
        ll y = *jt;
        ll z = *(++jt);

#ifdef DEBUG
    cout << "n = " << n << " i = " << i << ", x = " << x << ", w = " << w << ", y = " << y << ", z = " << z << endl;
    cout << "--- inc = " << n*(x - w)*(y - i) + (i - x)*(z - y) << endl;
#endif
        // Ver editorial para melhor entendimento
        ans += n*((x - w)*(y - i) + (i - x)*(z - y));
        S.insert(i);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
