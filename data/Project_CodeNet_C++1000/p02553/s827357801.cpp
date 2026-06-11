//#include <tourist>
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
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
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//g++ yarudake.cpp -std=c++17 -I .
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
//区間和
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, Q;
struct LazySegmentTree
{
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v)
    {
        int sz = (int)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r)
    {
        if (lazy[k] != 0)
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    //aからb-1
    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }
    //a+1からbまで aは含まない
    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return 0;
        if (a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=a*c;
    chmax(ans,a*d);
    chmax(ans, b * c);
    chmax(ans, b * d);
    cout<<ans<<"\n";
}