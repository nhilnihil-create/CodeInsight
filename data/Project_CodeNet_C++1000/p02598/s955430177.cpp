#include <bits/stdc++.h>

#ifdef DEBUG
#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))

#define LOGM(msg) (cerr << (msg))

#define LOGV(vec, sep) {                                        \
    cerr << #vec << " =";                                       \
    for (const auto& v : (vec)) cerr << " " << v;               \
    cerr << (sep); }

#define LOGA(arr, N, sep) {                                     \
        cerr << #arr << " =";                                   \
        for (int i = 0; i < N; ++i) cerr << " " << (arr)[i];    \
        cerr << (sep); }

#define LOGA2(arr, N, M, sep) {                                 \
        cerr << #arr << " =\n";                                 \
        for (int i = 0; i < N; ++i) {                           \
            for (int j = 0; j < M; ++j)                         \
                cerr << (arr)[i][j] << " ";                     \
            cerr << endl;                                       \
        } cerr << (sep); }
#else
#define LOG(var, sep)
#define LOGM(msg)
#define LOGV(vec, sep)
#define LOGA(arr, N, sep)
#define LOGA2(arr, N, M, sep)
#endif

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll count(ll m, const vector<ll>& xs)
{
    ll c = 0;

    for (auto x : xs)
        c += ((x + m - 1)/m - 1);

    return c;
}

ll solve(ll N, ll K, const vector<ll>& xs)
{
/*    ll to_zero = 0;

    for (auto x : xs)
        to_zero += (10*x + 3)/4;

LOG(to_zero, endl);
    if (to_zero <= K)
        return 0;
*/ 
    ll a = 1, b = 1000000000, ans = 0;

    while (a <= b)
    {
        auto m = a + (b - a)/2;

        if (count(m, xs) <= K)
        {
            ans = m;
            b = m - 1;
        } else
            a = m + 1;
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

    cout << ans << '\n';

    return 0;
}
