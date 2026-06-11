#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 200010;

int n;
PII edges[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
        scanf("%d%d", &edges[i].first, &edges[i].second);
    LL vsum = 0, esum = 0;
    for (int u = 1; u <= n; ++u) vsum += (LL)u * (n - u + 1);
    for (int i = 0; i < n - 1; ++i) {
        int minu = min(edges[i].first, edges[i].second);
        int maxu = max(edges[i].first, edges[i].second);
        esum += (LL)minu * (n - maxu + 1);
    }
    printf("%lld\n", vsum - esum);
    return 0;
}