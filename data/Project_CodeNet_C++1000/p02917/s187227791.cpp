#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n-1);
    rep(i, n-1) {
        scanf("%d", &b[i]);
    }
    int sum = 0;
    rep(i, n-1) {
        if (i == 0) continue;
        a[i] = min(b[i-1], b[i]);
        sum += a[i];
    }
    if (n != 2) {
        a[0] = b[0];
        a[n-1] = b[n-2];
        sum += a[0] + a[n-1];
    } else {
        sum = 2 * b[0];
    }
    // rep(i, n) {
    //     printf("%d", a[i]);
    //     if (n != n-1) printf(" ");
    //     else printf("\n");
    // }
    printf("%d\n", sum);
}