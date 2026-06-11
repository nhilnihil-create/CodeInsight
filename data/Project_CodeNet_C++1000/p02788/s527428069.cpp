#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

ll df(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return a / b - (a % b < 0);
}

ll dc(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return a / b + (a % b > 0);
}

template <class T>
class FT
{
    vector<T> ft;
public:
    FT(int n) : ft(n + 1)
    {
    }
    T rsq(int b)
    {
        T sum = 0;
        for (; b; b -= (b & (-b)))
            sum += ft[b];
        return sum;
    }
    void adjust(int k, T v)
    {
        for (; k < ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
    void adjust(int l, int r, T v)
    {
        adjust(l, v);
        adjust(r + 1, -v);
    }
};

int x[200000];
ll h[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<ll> vp, wp;
    vector<pair<ll, ll>> ev;
    FT<ll> ft(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> h[i];
        vp.push_back(x[i]);
        ev.emplace_back(x[i], h[i]);
    }
    sort(all(ev));
    for (int i = 0; i < n; ++i)
    {
        int xp, hp;
        tie(xp, hp) = ev[i];
        ft.adjust(i + 1, i + 1, hp);
    }
    sort(all(vp));
    wp = vp;
    reverse(all(wp));
    ll sol = 0;
    for (int i = 0; i < n; ++i)
    {
        int hp = ft.rsq(i + 1);
        if (hp <= 0) continue;
        int j = n - (lower_bound(all(wp), vp[i] + 2 * d, greater<ll>()) - wp.begin()) - 1;
        sol += dc(hp, a);
        ft.adjust(i + 1, j + 1, -dc(hp, a) * a);
    }
    cout << sol;
}
