#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int a[100005], b[100005], c[100005], eat[200005];
bool cmp1(int a,int b) {
    return a < b;
}
bool cmp2(int a,int b) {
    return a > b;
}
int main() {
    int x, y, n1, n2, n3, t = 1;
    long long ans = 0;
    cin >> x >> y >> n1 >> n2 >> n3;
    for (int i = 1; i <= n1; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n2; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n3; i++) scanf("%d", &c[i]);
    sort(a + 1, a + n1 + 1, cmp2);
    sort(b + 1, b + n2 + 1, cmp2);
    sort(c + 1, c + n3 + 1, cmp2);
    for (int i = 1; i <= x; i++) eat[i] = a[i];
    for (int i = x + 1; i <= x + y; i++) eat[i] = b[i - x];
    sort(eat + 1, eat + x + y + 1, cmp1);
    while (c[t] > eat[t] && t <= x + y && t <= n3) {
        eat[t] = c[t];
        t++;
    }
    for (int i = 1; i <= x + y; i++) ans += eat[i];
    printf("%lld\n", ans);
    return 0;
}
