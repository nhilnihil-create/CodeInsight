#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.1415926535897932384626
#define bits(n) __builtin_popcount(n)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> ok(n, true);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> ans(n);
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        if (h[a - 1] <= h[b - 1])
            ok[a - 1] = false;
        if (h[b - 1] <= h[a - 1])
            ok[b - 1] = false;
    }
    for(int i=0;i<n;i++)
    {
        if (ok[i])
            cnt++;
    }
    cout << cnt <<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}