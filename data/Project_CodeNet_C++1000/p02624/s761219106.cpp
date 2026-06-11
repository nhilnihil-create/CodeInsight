#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int32_t main()
{
    usaco();
    int n, ans = 0;
    cin >> n;
    vector <int> d(n+1, 1);
    for (int i = 2; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            ++d[j];
    for (int i = 1; i <= n; ++i) ans += i*d[i];
    cout << ans << '\n';
}
