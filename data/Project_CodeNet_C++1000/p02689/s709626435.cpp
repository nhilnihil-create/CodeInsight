#include <bits/stdc++.h>


using namespace std;




int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> H(N + 1);
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int h = H[i];
        bool good = true;
        for (auto e : graph[i]) {
            if (h <= H[e]) {
                good = false;
                break;
            }
        }

        if (good) {
            ans++;
        }
    }
    cout << ans << endl;
}
