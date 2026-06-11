#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
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
    int H, W, M;
    cin >> H >> W >> M;
    vint h(M), w(M);
    vint cntH(H), cntW(W);
    set<pair<int, int>> bombs;

    for (size_t i = 0; i < M; i++)
    {
        cin >> h[i] >> w[i];
        h[i]--;
        w[i]--;
        cntH[h[i]]++;
        cntW[w[i]]++;
        bombs.insert({h[i], w[i]});
    }
    int maxH = *max_element(all(cntH));
    int maxW = *max_element(all(cntW));
    int ans = maxH + maxW - 1;
    vint maxHs, maxWs;

    for (int i = 0;i<H;i++)
    {
        if(cntH[i]==maxH)maxHs.push_back(i);
    }
    for (int j = 0;j<W;j++)
    {
        if(cntW[j]==maxW)maxWs.push_back(j);
    }
    for (auto &&i : maxHs)
    {
        for (auto &&j : maxWs)
        {
            if (bombs.count({i, j}) == 0)
            {
                ans++;
                cout << ans;
                return 0;
            }
        }
    }

    cout << ans;
    return 0;
}