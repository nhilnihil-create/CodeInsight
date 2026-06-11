#include <bits/stdc++.h>


using namespace std;

int main(void) {
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> cost(N);
    vector<vector<int>> books(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            books[i].push_back(a);
        }
    }

    bool viable = false;
    int ans = INT_MAX;
    for (int i = 0; i < (1 << N); i++) {
        int spend = 0;
        vector<int> alg(M, 0);
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j)))
                continue;

            // chosen book j
            for (int k = 0; k < M; k++) {
                alg[k] += books[j][k];
            }
            spend += cost[j];
        }
        bool sat = true;
        for (int j = 0; j < M; j++) {
            if (alg[j] < X) {
                sat = false;
                break;
            }
        }
        if (sat) {
            ans = min(ans, spend);
        }
        viable |= sat;
    }
    if (viable) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
