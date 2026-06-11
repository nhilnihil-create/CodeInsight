#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;

#ifdef _DEBUG
#define DEBUG(x) cout << #x << ": " << x << endl;
#else
#define DEBUG(x)
#endif

#define ALL(obj) (obj).begin(), (obj).end()
#define BIT(n) (1LL << (n))

const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

ll op(ll a, ll b)
{
    return a + b;
}
ll e()
{
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // write code below
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segtree<ll, op, e> seg(a);
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            int p;
            ll x;
            cin >> p >> x;
            seg.set(p, seg.get(p) + x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
    // write code above
    return 0;
}
