#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(int N, const vector<ll>& xs)
{
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    if (A == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    auto k = N / (A + B);
    auto r = N - k*(A + B);

    auto ans = A*k + min(r, A);

    cout << ans << '\n';

    return 0;
}
