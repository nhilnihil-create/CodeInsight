//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const ll INF = 1e9;
const ll LINF = ll(1e18) + 1;
const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const ll Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
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
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n;
vector<ll> a;
struct fenwick_tree {
    typedef ll T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    cin >> n>>k;
    map<ll,ll>m;
    fenwick_tree f_tree(2001);
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        m[temp]++;
    }
    vector<ll> tentou(n);
    for (ll j = 0; j < n; j++) {
    tentou[j] = j - f_tree.sum(a[j]);
    f_tree.add(a[j], 1);
    }
    ll sumt=0;
    vector<ll> sum(2001);
    for(ll i=0;i<=2000;i++){
        sum[i]=sumt;
        sumt+=m[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll temp=(2*tentou[i]+(k-1)*sum[a[i]]);
        temp%=MOD;
        temp*=k;
        temp%=MOD;
        temp*=modinv(2,MOD);
        temp%=MOD;
        ans+=temp;
        ans%=MOD;

    }
    cout << ans << "\n";
}
