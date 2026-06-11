#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<int> G[N];
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        G[A-1].push_back(B-1);
        G[B-1].push_back(A-1);
    }

    int ans = 0;
    for (int u = 0; u < N; u++) {
        bool flag = true;
        for (int v : G[u]) {
            if (H[u] <= H[v]) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}