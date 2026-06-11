#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int cnt = 0;

    while (n) {
        cnt++;
        n /= k;
    }

    printf("%d\n", cnt);
}
