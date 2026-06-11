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
int ans[2005];
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (i <= x && j >= y) ans[x - i + j - y + 1]++;
            else if (i <= x && j <= x) ans[j - i]++;
            else if (i >= y && j >= y) ans[j - i]++;
            else if (i > x && j < y) ans[min(j - i, y - x + 1 - j + i)]++;
            else if (i <= x && j < y) ans[min(j - i, y - i - j + x + 1)]++;
            else if (i > x && j >= y) ans[min(j - i, j - x - y + i + 1)]++;
        }
    for (int i = 1; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
