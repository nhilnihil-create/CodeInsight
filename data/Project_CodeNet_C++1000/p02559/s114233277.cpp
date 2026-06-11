#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
template <typename T>
bool chmax(T &u, const T z)
{
    if (u < z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
template <typename T>
bool chmin(T &u, const T z)
{
    if (u > z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main()
{
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    rep(i, q)
    {
        int b;
        cin >> b;
        if (b == 0)
        {
            int p;
            ll x;
            cin >> p >> x;
            fw.add(p, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ll ans = fw.sum(l, r);
            cout << ans << endl;
        }
    }
    return 0;
}