// 2020-06-05 18:13
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> Tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    vector<long long> ans(N, 0);
    while (Q--) {
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }
    // 頂点0から根までBFSして漸化式で値を足していく
    vector<bool> visited(N, false);
    queue<int> Task;
    Task.push(0);
    while (!Task.empty()) {
        int f = Task.front();
        visited[f] = true;
        Task.pop();
        for (int t : Tree[f]) {
            if (visited[t]) continue;
            ans[t] += ans[f];
            Task.push(t);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i == N - 1 ? '\n' : ' ');
    }
    return 0;
}