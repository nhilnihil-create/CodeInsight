#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto& V : graph) {
        sort(V.begin(), V.end());
    }

    long long res = 0;

    for (int i = 0; i < n; ++i) {
        auto& V = graph[i];
        auto it = lower_bound(V.begin(), V.end(), i);
        int p = it - V.begin();
        int pre = -1;
        for (int j = 0; j < p; ++j) {
            res += (V[j] - pre) * 1LL * (p - j) * 1LL * (n - i);
            // cout << i << " " << V[j] << " " << (p - j) << " " << V[j] - pre <<  endl;
            pre = V[j];
        }
    }

    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        total += (n + 1 - i) * 1LL * i;
    }

    // cout << total << " " << n << " " << res << endl;
    res = total - res;

    cout << res << '\n';


    return 0;
}