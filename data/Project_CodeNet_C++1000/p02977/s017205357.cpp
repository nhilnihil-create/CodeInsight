// Written By NewbieChd
#include <cstdio>
using namespace std;

const int maxN = 100003;

int main() {
    int n, i;
    
    scanf("%d", &n);
    if ((n & -n) == n) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    
    printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
    for (i = 4; i < n; i += 2)
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", n + 1, i + 1, i + 1, i, n + 1, n + i, n + i, n + i + 1);
    if (!(n & 1)) {
        int x, y;
        x = n & -n, y = n ^ x ^ 1;
        printf("%d %d\n", n + x, n);
        printf("%d %d\n", y, n << 1);
    }
    return 0;
}
