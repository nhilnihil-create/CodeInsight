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

int n;

vector<pii> edges;

void e(int v, int u)
{
    edges.emplace_back(v, u);
}

void build_odd(int x, bool xtra = false)
{
    if (!xtra)
    {
        e(3, 1);
        e(1, 2);
        e(2, 3 + n);
        e(3 + n, 1 + n);
        e(1 + n, 2 + n);
        // T(3) is ready
        for (int y = 4; y + 1 <= x; y += 2)
        {
            e(y, 1);
            e(y + 1, y);
            e(1 + n, y + 1 + n);
            e(y + 1 + n, y + n);
        }
    }
    else
    {
        e(5, 1);
        e(1, 4);
        e(4, 5 + n);
        e(5 + n, 1 + n);
        e(1 + n, 4 + n);
        e(2, 1);
        e(3, 2);
        e(1 + n, 3 + n);
        e(3 + n, 2 + n);
        // T(5) is ready
        for (int y = 6; y + 1 <= x; y += 2)
        {
            e(y, 1);
            e(y + 1, y);
            e(1 + n, y + 1 + n);
            e(y + 1 + n, y + n);
        }
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
    if (__builtin_popcount(n) == 1)
    {
        cout << "No\n";
        return 0;
    }
    if (n == 6)
    {
        cout << "Yes\n5 4\n4 1\n3 1\n1 2\n2 9\n9 7\n7 8\n8 6\n7 11\n11 10\n11 12\n";
        return 0;
    }
    int u = 0;
    {
        int nn = n;
        while (~nn & 1)
        {
            nn >>= 1;
            ++u;
        }
    }
    if (!u)
    {
        build_odd(n);
    }
    else
    {
        build_odd(n - 1, u == 1);
        int n1 = n - (1 << u);
        e(n, n1);
        e((1 << u) + 1 + n, 2 * n);
    }
    cout << "Yes\n";
    for (auto edge : edges)
    {
        /*if (edge.fi <= n)
            cout << edge.fi;
        else
            cout << "x" << edge.fi - n;
        cout << ' ';
        if (edge.se <= n)
            cout << edge.se;
        else
            cout << "x" << edge.se - n;
        cout << endl;/**/
        cout << edge.fi << ' ' << edge.se << '\n';
    }

    return 0;
}