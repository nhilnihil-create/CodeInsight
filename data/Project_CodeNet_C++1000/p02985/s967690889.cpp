#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long dfs(int K, vector<vector<int>> &graph, int now, int from) {
    int can_use_color_num;
    if (from == -1) {
        can_use_color_num = K - 1;
    } else {
        can_use_color_num = K - 2;
    }

    if (K < graph[now].size()) {
        return 0;
    } else {
        long long case_num = 1;
        for (int e : graph[now]) {
            if (e == from) continue;

            case_num *= can_use_color_num;
            can_use_color_num--;
            case_num %= mod;
        }

        for (int e : graph[now]) {
            if (e == from) continue;
            case_num *= dfs(K, graph, e, now);
            case_num %= mod;
        }
        return case_num;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long answer = K * dfs(K, graph, 0, -1);
    answer %= mod;
    cout << answer << endl;
    return 0;
}