#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int temp;
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        temp = sqrt(n - i) + 1;
        for (int j = 1; j < temp; ++j) {
            if ((n - i) % j == 0) {
                ans += 2;
                if ((n - i) / j == j) {
                    --ans;
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}