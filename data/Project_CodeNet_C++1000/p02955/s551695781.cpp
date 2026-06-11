#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
string make_string(T N)
{
    string ret;
    T now = N;
    while (now > 0)
    {
        T x = now % 10;
        ret += (char)('0' + x);
        now /= 10;
    }
    reverse(all(ret));
    return ret;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));
//nの約数を小さい順に列挙した配列を返す
//計算量:O(√n)
template <typename T>
vector<T> divisor(T n)
{
    vector<T> ret1, ret2;
    for (T i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret1.push_back(i);
            if (i * i != n)
                ret2.push_back(n / i);
        }
    }
    T siz = ret2.size();
    for (T i = (siz - 1); i >= 0; i--)
    {
        ret1.push_back(ret2[i]);
    }
    return (ret1);
}

template <typename T>
struct BIT
{
private:
    vector<T> bit;
    T n;
    T sum(T x)
    {
        T ret = 0;
        while (x > 0)
        {
            ret += bit[x];
            x -= x & -x;
        }
        return ret;
    }

public:
    BIT(T n0) : bit(n0 + 1, 0), n(n0) {}
    BIT(T n0, vector<T> &A) : bit(n0 + 1, 0), n(n0)
    {
        for (int i = 1; i <= n; i++)
            bit[i] = A[i - 1];
        for (int i = 1; i < n; i++)
            bit[i + (i & -i)] += bit[i];
    }
    T sum(T l, T r)
    {
        return sum(r + 1) - sum(l);
    }
    T at(T x)
    {
        return sum(x, x);
    }
    void add(T p, T x)
    {
        T i = p + 1;
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
};
/*
BIT<long long> data(n);などで宣言(初期値は0)
または配列の値をvector<long long> a(n)などで初期化したいとき
BIT<long long> data(n,a);で宣言
以下0-indexedと仮定する
data.sum(l,r):区間[l,r]の和
data.at(i):i番目の値
data.add(i,x):i番目にxを加算 
*/
int main()
{
    cout << fixed << setprecision(30);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    loop(i, N) cin >> A[i];
    ll S = Sum(A);
    vector<ll> div = divisor(S);
    ll siz = div.size();
    ll ans = 1;
    loop(i, siz)
    {
        ll now = div[i];
        //まず、A[i]%nowを小さい順に並べる
        vector<ll> data(N);
        loop(j, N) data[j] = A[j] % now;
        sort(all(data));
        BIT<ll> data1(N), data2(N);
        loop(j, N)
        {
            data1.add(j, data[j]);
            data2.add(j, now - data[j]);
        }
        //分割
        ll count;
        loop(j, N - 1)
        {
            if (data1.sum(0, j) == data2.sum(j + 1, N - 1))
            {
                count = data1.sum(0, j);
                break;
            }
        }
        if (count <= K)
            ans = now;
    }
    putout(ans);
    return 0;
}
