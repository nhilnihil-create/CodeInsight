#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K; cin >> N >> K;
    vector<pair<int,int>> edges;
    if (K == 0) {
        // complete graph
        for (int u = 1; u <= N-1; u++) {
            for (int v = u+1; v <= N; v++) {
                edges.push_back(make_pair(u, v));
            }
        }
    } else if (K > N * (N-1) / 2 - (N-1)) {
        // nop
    } else {
        for (int v = 1; v < N; v++) {
            edges.push_back(make_pair(v, N));
        }
        int surplus = (N-1) * (N-2) / 2 - K;
        for (int u = 1; u <= N-2 && surplus > 0; u++) {
            for (int v = u + 1; v <= N-1 && surplus > 0; v++) {
                edges.push_back(make_pair(u, v));
                surplus--;
            }
        }
    }
    if (edges.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << edges.size() << endl;
        for (const auto& e : edges) {
            cout << e.first << " " << e.second << endl;
        }
    }
}
