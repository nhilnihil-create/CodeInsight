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

ll solve(ll, ll D, const vector<ii>& xs)
{
    ll ans = 0;

    for (auto p : xs)
    {
        auto x = p.first, y = p.second;

        ans += (x*x + y*y <= D*D ? 1 : 0);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, D;
    cin >> N >> D;

    vector<ii> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i].first >> xs[i].second;

    auto ans = solve(N, D, xs);

    cout << ans << '\n';

    return 0;
}
