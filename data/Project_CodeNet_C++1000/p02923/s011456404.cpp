#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << " --> " << x << endl;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
        cout << it << " ";        \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define deb3a(v)                               \
    cout << #v << "-->" << endl;               \
    for (auto it : v)                          \
    {                                          \
        cout << it.fi << " " << it.se << endl; \
    }
#define mod 100000000000007
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int mI(int a, int m)
{
    return power(a, m - 2, m);
}
vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

#define MAXN 10000001

void solve()
{
    int n;
    cin >> n;
    vec v(n);
    //int ans = 0;
    stack<int> ss;
    fo(i, n)
    {
        cin >> v[i];
    }
    vec ans(n, 0);
    int anss = 0;
    ans[n - 1] = 0;
    for(int i=n-2;i>=0;i--){
        if(v[i+1]<=v[i]){
            ans[i] = 1 + ans[i + 1];
        }
        else{
            ans[i] = 0;
        }
        anss = max(anss, ans[i]);
    }
    cout << anss;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

    // FILE *fin = freopen("ip.txt","r",stdin);
    // FILE *fout = freopen("op.txt","w",stdout);
    int t = 1, nn = 1;
    //cin >> t;
    while (t--)
    {
        // cout << "Case #" << nn << ":"
        //      << " ";
        // nn++;
        solve();
    }
}