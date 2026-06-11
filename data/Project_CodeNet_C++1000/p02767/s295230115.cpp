#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 1e9;

    for (int i = 1; i <= 100; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            dist += (a[j] - i) * (a[j] - i);
        }
        res = min(res, dist);
    }

    printf("%d\n", res);
}
