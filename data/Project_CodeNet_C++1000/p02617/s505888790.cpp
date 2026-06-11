#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    long long ans = n;
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        ans -= 1LL * x * (n - y + 1);
        ans += 1LL * i * (n - i + 1);
    }
    printf("%lld\n", ans);
    return 0;
}