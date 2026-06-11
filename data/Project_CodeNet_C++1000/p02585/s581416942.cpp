/* 
  Krishnakant Tiwari
  Problem Link:
  
 */
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _cin                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"
#define pb push_back
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define repd(i, a, b) for (ll i = a; i >= b; --i)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define sz(x) (ll) x.size()
#define sll set<ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define precise(x) cout << fixed << setprecision(x)
const ll MAX = 1000004;
const ll INF = 1e18L + 5;
template <typename Arg1>
void pn(Arg1 &&arg1)
{
    cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1 &&arg1, Args &&... args)
{
    cout << arg1 << "\n";
    pn(args...);
}
template <typename Arg1>
void ps(Arg1 &&arg1)
{
    cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1 &&arg1, Args &&... args)
{
    cout << arg1 << " ";
    ps(args...);
}
template <typename Arg1>
void read(Arg1 &&arg1)
{
    cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1 &&arg1, Args &&... args)
{
    cin >> arg1;
    read(args...);
}

ll g[MAX];
ll a[MAX];

void solve()
{
    ll n, k;
    read(n, k);
    ll p[n], c[n];
    rep(i, 0, n)
    {
        read(p[i]);
        p[i]--;
    }
    rep(i, 0, n) read(c[i]);
    ll ans = -INF;
    rep(i, 0, n)
    {
        ll cur_i = i;
        ll c_s = 0;
        ll c_l = 0;
        while (true)
        {
            c_s += c[p[cur_i]];
            c_l++;
            cur_i = p[cur_i];
            if (cur_i == i)
                break;
        }

        ll path = 0;
        ll cnt = 0;
        while (true)
        {
            cnt++;
            path += c[p[cur_i]];
            if (cnt > k)
                break;
            ll num = (k - cnt) / c_l;
            ll val = path + max(0ll,c_s) * num;
            ans = max(ans, val);

            cur_i = p[cur_i];
            if (cur_i == i)
                break;
        }
    }
    pn(ans);
}

int main()
{

    _cin
    // ll tc;
    // cin>>tc;
    // while(tc--){
    solve();
    // }
}