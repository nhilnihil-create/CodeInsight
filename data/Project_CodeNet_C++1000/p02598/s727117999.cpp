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
ll n, k;
vector<ll> a;
ll check(ll h)
{
    ll count = 0;
    rep(i, n)
    {
        count+=(a[i]+h-1)/h;
        count--;
    }
    //cout << h << " " << count << "\n";
    return count;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    ll l = 0;
    ll r = LINF;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        if (check(mid) > k)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << "\n";
}
