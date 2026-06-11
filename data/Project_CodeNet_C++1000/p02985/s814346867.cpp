#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int n, k;
vector<vector<int>> to;
ll ans = 1;

// p:親のID
// b:既に訪れた兄弟の数
// is_grand:親の親がいるか
void dfs(int x, int p, int b, bool is_grand) {
    if (p == -1) ans = (ans * k) % mod;
    else if (!is_grand) ans = (ans * (k - 1 - b)) % mod;
    else ans = (ans * (k - 2 - b)) % mod;

    int b_next = 0;
    for (auto v : to[x]) {
        if (v == p) continue;
        bool is_grand_next = (p != -1);
        dfs(v, x, b_next, is_grand_next);
        b_next++;
    }
    return;
}

int main()
{
    cin >> n >> k;
    to.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0, -1, 0, false);
    cout << ans << endl;
    return 0;
}
