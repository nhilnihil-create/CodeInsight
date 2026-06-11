#include <bits/stdc++.h>
using namespace std;

long N, M, ans;
vector<long> H;
vector<set<long>> G;

int main(void) {

    cin >> N >> M;
    H.resize(N+1);
    G.resize(N+1);

    for (long i = 1; i <= N; i++) {
        cin >> H[i];
    }

    for (long i = 0; i < M; i++) {
        long a, b; cin >> a >> b;
        G[a].emplace(b);
        G[b].emplace(a);
    }

    for (long i = 1; i <= N; i++) {
        bool flag = true;
        for (auto e: G[i]) {
            if (H[i] <= H[e]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}