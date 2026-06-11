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
int val(int a, int b)
{
    if (a > b)
        swap(a, b);
    return a * 1001 + b + 1;
}
int N;
vint A(1100);
vvint graph(1100000);
vint indeg(1100000, -1);
vint dist(1100000);
vint seen(1100000); //1 : 行きがけ 2 : 見た後
int dfs(int p)
{
    if (seen[p] == 2)
        return dist[p];

    seen[p]=1;
    for (auto &&i : graph[p])
    {
        if (seen[i] == 1)
        {
            cout << -1 << endl;
            exit(0);
        }
        
        chmax(dist[p], dfs(i) + 1);
    }
    seen[p]=2;
    return dist[p];
};
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            cin >> A[j];
            A[j]--;
        }
        graph[0].push_back(val(i,A[0]));
        for (int j = 0; j < N - 2; j++)
        {
            indeg[val(i, A[j])] = 0;
            graph[val(i, A[j])].push_back(val(i, A[j + 1]));
            if (indeg[val(i, A[j + 1])] == -1)
                indeg[val(i, A[j + 1])] = 0;
            indeg[val(i, A[j + 1])]++;
        }
    }
    cout << dfs(0);
    return 0;
}