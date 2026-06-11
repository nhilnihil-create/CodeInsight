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

class Solution {
public:
    int solve(int n, int k, vector<pair<int,int>>& edges) {
        graph.clear();
        graph.resize(n);
        
        init(k + 123);

        for (auto& e : edges) {
            int u = e.first, v = e.second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int res = dfs(0, -1, k);
        return res;
    }

private:
    vector<vector<int>> graph;
    vector<int> sizes;


    const static long long MOD = 1000000007;

    vector<long long> pow2;
    vector<long long> F;
    vector<long long> IF;

    long long dfs(int u, int p, int K) {
        long long M = 1;
        if (p != -1) {
            int cnt = graph[u].size() - 1;
            if (cnt == 0) {
                return 1;
            }
            M = nAr(K - 2, cnt);
        } else {
            int cnt = graph[u].size();
            M = nAr(K, cnt + 1);
        }

        long long res = 1;
        for (auto v : graph[u]) {
            if (v == p) {
                continue;
            }
            (res *= dfs(v, u, K)) %= MOD;
        }
        (res *= M) %= MOD;
        return res;
    }

    long long norm(long long a) {
        a %= MOD;
        if (a < 0) {
            a += MOD;
        }
        return a;
    }

    long long inverse(long long a) {
        long long b = MOD;
        long long u = 0, v = 1;
        a = norm(a);
        while (a != 0) {
            long long d = b / a;
            b -= d * a;
            u -= d * v;
            swap(a, b);
            swap(u, v);
        }
        return norm(u);
    }

    long long powM(long long x, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }

    void init(int n) {
        F.clear();
        F.resize(n + 1, 1);
        IF = F;
        pow2.clear();
        pow2.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }

        for (int i = 1; i <= n; ++i) {
            F[i] = F[i - 1] * i % MOD;
        }
        IF[n] = inverse(F[n]);
        for (int i = n - 1; i > 0; --i) {
            IF[i] = IF[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        long long res = F[n] * IF[r] % MOD * IF[n - r] % MOD;
        return res;
    }

    long long nAr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        return F[n] * IF[n - r] % MOD;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }

    Solution sol;
    cout << sol.solve(n, k, edges) << "\n";

    return 0;
}