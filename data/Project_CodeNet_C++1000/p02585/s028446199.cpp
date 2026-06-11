#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define input \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#else
#define debug(...) 4
#define input 4
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
#define int long long
int32_t main() {
    input;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int cost[n];
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    ll total_ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        vector<int> vis(n);
        vector<int> costs;
        int x = i;
        long long sum = 0;
        while (!vis[x]) {
            vis[x] = 1;
            costs.push_back(cost[x]);
            sum += cost[x];
            x = p[x];
        }
        int sz = costs.size();
        if(sum > 0) {
            ll ans = 1ll * sum * ((k / sz) - 1);
            int rem = sz + (k % sz);
            for(int j = 0; j < rem; j++) {
                ans += costs[j % sz];
                total_ans = max(ans, total_ans);
            }
        }
        else {
            ll ans = 0;
            for(int j = 0; j < sz + k % sz; j++) {
                ans += costs[j % sz];
                total_ans = max(ans, total_ans);
            }
        }            
    }
    cout << total_ans;


}

