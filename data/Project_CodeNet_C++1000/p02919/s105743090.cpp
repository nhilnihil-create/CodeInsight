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
vector<ll> a, b, c;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        m[temp] = i + 1;
    }
    set<ll> s;
    s.insert(0);
    s.insert(n + 1);
    ll ans = 0;
    for (ll i = n; i >= 1; i--)
    {
        ll idx = m[i]; //iのインデックス
        auto itr = s.lower_bound(idx);
        auto copy = itr;
        vector<ll> l(2, -1), r(2, -1);
        for (ll i = 0; i < 2; i++)
        {
            if (itr == s.begin())
            {
                break;
            }
            else
            {
                itr--;
                l[i] = *itr;
            }
        }
        for (ll i = 0; i < 2; i++)
        {
            if (copy == s.end())
            {
                break;
            }
            else
            {
                r[i] = *copy;
                copy++;
            }
        }
        //debug(l);
        //debug(r);
        if (l[1] != -1 && r[0] != -1)
        {
            ans += i * (r[0] - idx) * (l[0] - l[1]);
        }
        if (l[0] != -1 && r[1] != -1)
        {
            ans += i * (r[1] - r[0]) * (idx - l[0]);
        }
        s.insert(idx);
    }
    cout << ans << "\n";
}
