#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    vector<int> h(n+1);
    vector<int> adjMax(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adjMax[u] = max(adjMax[u], h[v]);
        adjMax[v] = max(adjMax[v], h[u]);
    }

    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > adjMax[i]) {
            cnt++;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
