#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    for (int i = 1; i <= 2000; i++) {
        if ((int)floor(0.08 * i) == a && (int)floor(0.1 * i) == b) return 0 * printf("%d\n", i); 
    }

    printf("-1\n");
}
