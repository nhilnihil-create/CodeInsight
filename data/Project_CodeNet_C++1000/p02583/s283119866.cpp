#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] == a[j]) continue;
                if (a[i] == a[k]) continue;
                if (a[j] == a[k]) continue;

                int sum = a[i] + a[j] + a[k];
                int mx = max({a[i], a[j], a[k]});
                if (mx < sum - mx) res++;
            }
        }
    }

    printf("%d\n", res);
}
