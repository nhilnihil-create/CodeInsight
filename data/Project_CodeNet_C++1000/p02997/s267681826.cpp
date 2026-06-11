#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int k_possible = (n - 1) * (n - 2) / 2;
    if (k > k_possible) {
        printf("-1\n");
        return 0;
    }

    int num = (n - 1) + (k_possible - k);
    printf("%d\n", num);
    for (int v = 1; v <= n - 1; v++) {
        printf("%d %d\n", v, n);
    }

    num = k_possible - k;
    for (int i = 1; i <= n - 1 && num; i++) {
        for (int j = i + 1; j <= n - 1 && num; j++) {
            printf("%d %d\n", i, j);
            --num;
        }
    }

    return 0;
}
