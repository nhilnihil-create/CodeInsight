#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
ll n, a[maxn], ans = 0;

int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n, greater<int>());
    ans = a[0];
    for (int i = 1; i < n / 2; i++) ans += a[i] * 2;
    if (n % 2) ans += a[n / 2];
    printf("%lld", ans);
    return 0;
}