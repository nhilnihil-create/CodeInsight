/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define LL long long
#define ll long long
#define LD double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
const ll N = 1e5 + 5, mod = 1e9 + 7;
ll x, y, n, k, out = 1;
vector<int> v[N];

void dfs(int u, int p = -1, ll cur = k) {
    out = (out * cur) % mod;

    ll ps = 0;
    for (int i = 0; i < v[u].size(); i++)
        if (v[u][i] != p) {
            dfs(v[u][i], u, k - 1 - ps - (p != -1));
            ps++;
        }
}

int main() {
    HabdModeActive

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);
    cout << out;


    return 0;
}