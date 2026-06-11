#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N, T;
    cin >> N >> T;
    vint A(N), B(N);
    vector<pair<int, int>> AB(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
        AB[i] = {A[i], B[i]};
    }
    sort(all(AB));

    auto dp = make_v<int>(N + 1, T + 1); //dp[i][j] := i番目までの品物で得られる最大の満足度
    rep(i, N)
    {
        rep(j, T + 1)
        {
            if (j < AB[i].first)
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - AB[i].first] + AB[i].second);
            }

        }
    }
    int ans = 0;
    rep(i, N + 1)
    {
        int M = 0;
        rep2(j, i, N)
        {
            chmax(M, AB[j].second);
        }
        chmax(ans, dp[i][T - 1] + M);
    }
    cout << ans;
    return 0;
}