#pragma GCC optimize("O3")
#pragma G++ optimize("O3")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define mst(a, b) memset((a), (b), sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pi acos(-1)
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
#define ls t[root << 1]
#define rs t[root << 1 | 1]
#define tr t[root]
#define lowbit(x) x &(-x)
#define all(x) (x).begin(), (x).end()
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%d", x)
#define debug(x) cout << x << endl
#define mod(x) (x % mod + mod) % mod

template <typename T>
void read(T &x)
{
    x = 0;
    char ch = getchar();
    ll f = 1;
    while (!isdigit(ch))
    {
        if (ch == '-')
            f *= -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}

const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 7;
const int maxm = 1e3 + 7;
const int mod = 1e9 + 7;

#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//template<typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int pre[maxn];
int siz[maxn];
int Find(int x)
{
    if (x == pre[x])
        return x;
    return pre[x] = Find(pre[x]);
}
int ans=1;
void join(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if (fx!=fy)
    {
        pre[fx]=fy;
        siz[fy]+=siz[fx];
        ans=max(ans,siz[fy]);
    }
}
int main()
{
    IO;
    for (int i = 1; i < maxn; ++i)
    {
        pre[i] = i;
        siz[i] = 1;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        join(x, y);
    }
    cout<< ans << endl;
    return 0;
}
