
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;


int n, q;
vector<int> to[200005];
int sum[200005];
LL ans[200005];
LL add = 0;


void dfs(int curr, int from=-1) {
    add += sum[curr];
    ans[curr] = add;
    for (auto next: to[curr]) {
        if (next != from) {
            dfs(next, curr);
        }
    }
    add -= sum[curr];
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    cin >> n >> q;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        sum[p] += x;
    }
    dfs(1);

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
