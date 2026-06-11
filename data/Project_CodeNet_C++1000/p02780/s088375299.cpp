#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

double E(ll n)
{
    return (n + 1)/2.0;
}

double solve(int N, int K, const vector<ll>& xs)
{
    double sum = 0.0, ans;

    for (int i = 0; i < K; ++i)
        sum += E(xs[i]);

    ans = sum;

    for (int i = K; i < N; ++i)
    {
        sum = sum - E(xs[i - K]) + E(xs[i]);
#ifdef DEBUG
    cout << "res = " << res << ", ans = " << ans << endl;
#endif
        ans = max(ans, sum);
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, K, xs);

    cout.precision(15);
    cout << fixed << ans << '\n';

    return 0;
}
