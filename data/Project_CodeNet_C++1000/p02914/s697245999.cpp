#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
 
template <typename T1, typename T2> bool chkmin(T1 &x, T2 y) { return y < x ? (x = y, true) : false; }
template <typename T1, typename T2> bool chkmax(T1 &x, T2 y) { return y > x ? (x = y, true) : false; }

const int N = 100005;
const int LOG = 61;
int n;
ll a[N];
ll basis[LOG];

void add(ll  x)
{
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (~x & (1LL << i)) continue;
        if (!basis[i])
        {
            basis[i] = x;
            return;
        }
        x ^= basis[i];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    
    cin >> n;
    ll X = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        X ^= a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        add(a[i] & (~X));
    }
    ll A = 0;
    for (int j = LOG - 1; j >= 0; --j) if (~X & (1LL << j))
    {
        ll B = A ^ (1LL << j);
        // want to check if B is representable by the basis in intereseting bits
        ll BB = B;
        bool ok = true;
        for (int i = LOG - 1; i >= j; --i) if (~X & (1LL << i))
        {
            if (~B & (1LL << i)) continue;
            if (!basis[i])
            {
                ok = false;
                break;
            }
            B ^= basis[i];
        }
        if (ok)
            A = BB;
    }
    cout << X + 2 * A << '\n';


    return 0;
}