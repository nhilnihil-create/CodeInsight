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
    string s, t, ss;
    cin >> s >> t;
    ss = s + s;
    ll n = s.size(), m = t.size();
    set<int> pos[26];
    for (int i = 0; i < n; i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (s[i] == c)
                pos[c-'a'].insert(i+1);
        }
    }
    bool ok = true;
    for (size_t i = 0; i < m; i++)
    {
        if (pos[t[i]-'a'].empty())
        {
            cout << -1;
            return 0;
        }
    }
    ll ans = 0;
    ll now = 0;
    for (size_t i = 0; i < m; i++)
    {
        char c = t[i]-'a';
        if (now >= *(--pos[c].end()))
        {
            ans += n - now;
            now = 0;
        }
        auto newpos=*pos[c].lower_bound(now+1);
        ans += newpos - now;
        now = newpos;
    }
    cout << ans;
    return 0;
}
