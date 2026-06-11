#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 111;
const ll mod = 1e9 + 7;
int a[maxn];
int m = 0, p[maxn];
void divide(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) n /= i, ++cnt;
            p[i]++;
        }
    }
    if (n > 1) p[n]++;
}
int main() {
    int n;
    scanf("%d", &n);
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        divide(a[i]);
    }
    int tot = 0;
    int tot2 = 0;
    int flag1 = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (p[i] == 0) continue;
        if (p[i] != 1) flag1 = 1;
        if (p[i] == n) ++tot2;
    }
    if (!flag1) {
        puts("pairwise coprime");
    } else if (tot2 == 0) {
        puts("setwise coprime");
    } else {
        puts("not coprime");
    }
    return 0;
}