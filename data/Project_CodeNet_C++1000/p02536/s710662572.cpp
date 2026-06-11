#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    int A[M], B[M];
    vector<int> adj[N];
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }
    bool vis[N]{};
    int k = 0;
    deque<int> q;
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        q.push_back(i);
        vis[i] = true;
        k++;
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            for (int j : adj[u]) {
                if (vis[j]) continue;
                q.push_back(j);
                vis[j] = true;
            }
        }
    }
    cout << k - 1 << "\n";
    return 0;
}