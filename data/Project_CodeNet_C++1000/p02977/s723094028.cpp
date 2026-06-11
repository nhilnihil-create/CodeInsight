#include <cstdio>

using namespace std;

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    if (__builtin_popcount(n) == 1) {
        puts("No");
        
        return 0;
    }
    
    puts("Yes");
    
    if (n % 4 == 3) {
        for (i = 1; i < n * 2; i++) printf("%d %d\n", i, i + 1);
    } else if (n % 4 == 1) {
        for (i = 1; i < n - 2; i++) printf("%d %d\n", i, i + 1);
        printf("%d %d\n", n - 2, n + 1);
        for (i = 1; i < n - 2; i++) printf("%d %d\n", i + n, i + n + 1);
        printf("%d %d\n", n - 1, n);
        printf("%d %d\n", n, 1);
        printf("%d %d\n", 1, n * 2 - 1);
        printf("%d %d\n", n * 2 - 1, n * 2);
    } else if (n % 4 == 2) {
        for (i = 1; i < n - 3; i++) printf("%d %d\n", i, i + 1);
        printf("%d %d\n", n - 3, n + 1);
        for (i = 1; i < n - 3; i++) printf("%d %d\n", i + n, i + n + 1);
        printf("%d %d\n", n - 2, n - 1);
        printf("%d %d\n", n - 1, 1);
        printf("%d %d\n", 1, n * 2 - 2);
        printf("%d %d\n", n * 2 - 2, n * 2 - 1);
        printf("%d %d\n", n - 1, n);
        printf("%d %d\n", 2, n * 2);
    } else {
        int x = __builtin_ctz(n) + 1;
        
        for (i = 1; i < n - 1; i++) printf("%d %d\n", i, i + 1);
        printf("%d %d\n", n - 1, n + 1);
        for (i = 1; i < n - 1; i++) printf("%d %d\n", i + n, i + n + 1);
        printf("%d %d\n", n - 1, n);
        printf("%d %d\n", n + (1 << x) - 2, n * 2);
    }
    
    return 0;
}
