#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;

const int N = 5005;
int n, k, p[N], c[N];
int vis[N];
vector<int> vs;
ll ans = -1e17;

void calc(int start) {
    if (vs.empty()) return;
    // for (int i : vs) {
    //     cout << i + 1 << " ";
    // }
    // cout << endl;
    auto nv = vs;
    ll round = 0;
    for (auto v : nv) {
        vs.push_back(v);
        round += c[v];
    }
    vector<ll> sum;
    sum.push_back(0);
    for (int i = 0; i < vs.size(); i++) {
        sum.push_back(sum.back() + c[vs[i]]);
    }
    for (int i = 0; i < vs.size(); i++) {
        for (int j = i+1; j < vs.size(); j++) {
            ll cur = sum[j] - sum[i];
            int rest = k - (j-i);
            if (rest < 0) {
                continue;
            }
            if (round > 0) {
                cur += round * (rest / nv.size());
            }
            if (cur > ans) {
                ans = cur;
            }
        }
    }
}

void dfs(int cur) {
    if (vis[cur]) {
        calc(cur);
        vs.clear();
        return;
    }
    vis[cur] = 1;
    vs.push_back(cur);
    dfs(p[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    cout << ans << endl;

    return 0;
}