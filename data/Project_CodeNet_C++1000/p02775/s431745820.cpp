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
const int Keta_MAX = 1000000;
string S;
int keta;
auto memo = make_v<ll>(Keta_MAX + 1, 2);
ll solve(int k, bool pitari)
{

    int now = S[k] - '0';
    if (k == keta)
    {
        return pitari == false;
    }
    if (memo[k][pitari] != -1)
        return memo[k][pitari];
    if (pitari)
    {
        memo[k][pitari] = min(now + solve(k + 1, true), now + 1 + solve(k + 1, false));
    }
    else
    {
        memo[k][pitari] = min(9 - now + solve(k + 1, false), 10 - now + solve(k + 1, true));
    }
    return memo[k][pitari];
}
int main()
{
    fill_v(memo, -1);

    cin >> S;
    keta = S.size();
    cout << min(solve(0, true), solve(0, false) + 1);
    return 0;
}