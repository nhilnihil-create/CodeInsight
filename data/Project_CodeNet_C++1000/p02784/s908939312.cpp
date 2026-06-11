#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, n;
    scanf("%d%d", &h, &n);

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
    }

    if (sum >= h) printf("Yes\n");
    else printf("No\n");
}
