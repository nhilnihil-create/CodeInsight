#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        n -= x;
    }
    if (n < 0) n = -1;
    printf("%d\n", n);
    return 0;
}
