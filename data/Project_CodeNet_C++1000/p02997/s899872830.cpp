#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
    int N, K;  cin >> N >> K;
    if (K > (N - 1) * (N - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<P> G;
    for (int i = 1; i < N; ++i) {
        G.push_back(P(0, i));
    }
    int cnt = (N - 1) * (N - 2) / 2 - K;
    int i = 1, j = 2;
    while (cnt--) {
        if (j == N) {
            ++i;
            j = i + 1;
        }
        G.push_back(P(i, j));
        ++j;
    }
    cout << G.size() << endl;
    for (P e : G) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
}
