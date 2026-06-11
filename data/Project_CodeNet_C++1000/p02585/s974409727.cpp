//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n)
    {
        cin >> c[i];
    }
    ll ans_t = -LINF;
    rep(i, n)
    {
        ll ss = 0;
        ll cur = p[i];
        ll score = c[p[i]];
        ll count = 1;
        while (cur != i)
        {
            count++;
            score += c[p[cur]];
            cur = p[cur];
        }
        if (score >= 0 && k > count * 2)
        {
            ss = score * (k / count - 1);
        }
        ll kk = k;
        if (k > count * 2)
        {
            kk = count + k % count;
        }
        ll sum1 = 0;
        ll now = i;
        rep(j, kk)
        {
            sum1 += c[p[now]];
            now = p[now];
            chmax(ans_t, sum1 + ss);
        }
    }
    cout << ans_t << "\n";
}
