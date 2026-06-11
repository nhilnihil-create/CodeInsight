#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int k, n, a[200010];

int main() {
    int maxt = 0;
    scanf("%d%d%d", &k, &n, &a[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
        maxt = max(maxt, a[i] - a[i - 1]);
    }
    maxt = max(maxt, a[1] - a[n] + k);
    printf("%d", k - maxt);
    return 0;
}