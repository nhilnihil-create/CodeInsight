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
template <typename Set>
struct Monoid
{
    using Op = function<Set(Set, Set)>;
    const Op f;
    const Set e;
    Monoid(const Op F, const Set E) : f(F), e(E)
    {
    }
};
template <typename Set>
struct SegmentTree
{
    using Op = function<Set(Set, Set)>;
    Monoid<Set> M;
    Set e;
    int size; //一番下以外の区間たち全部の数
    vector<Set> seg;
    SegmentTree(int n, const Monoid<Set> &M) : M(M)
    {
        size = 1;
        while (size < n)
        {
            size <<= 1;
        }
        e = M.e;
        seg.assign(2 * size, e);
    }
    void set(int k, const Set &x)
    {
        seg[k + size] = x;
    }
    void build()
    {
        for (int k = size - 1; k > 0; k--)
        {
            seg[k] = M.f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    void update(int k, const Set &x)
    {
        k += size;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = M.f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    Set query(int a, int b) //区間[a,b)に対して演算したやつを返す
    {
        Set L = e, R = e;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) //ループ一回ごとにa,bは親に向かう
        {
            if (a & 1) //a%2==1なら
            {
                L = M.f(L, seg[a++]);
            }
            if (b & 1)
            {
                R = M.f(seg[--b], R);
            }
        }
        return M.f(L, R);
    }
};
int main()
{
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> xh(N);
    vll X(N);
    for (size_t i = 0; i < N; i++)
    {
        ll h;
        cin >> X[i] >> h;
        xh[i] = {X[i], h};
    }
    sort(all(X));
    sort(xh.begin(), xh.end());
    ll ans = 0;
    vll s(N + 1);
    for (int i = 0; i < N; i++)
    {
        ll x = xh[i].first, h = xh[i].second;
        if (s[i] < h)
        {
            ll need = (h - s[i] + A - 1) / A;
            ll right = x + 2 * D;
            int idx = upper_bound(all(X), right) - X.begin();
            s[i] += need * A;
            s[idx] -= need * A;
            ans += need;
        }
        s[i + 1] += s[i];
    }
    cout << ans << endl;

    return 0;
}