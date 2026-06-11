#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN];
int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int step = 1, ok = 0; step <= k && !ok; step++) {
        for (int i = 1; i <= n; i++) b[i] = 0;
        for (int i = 1; i <= n; i++) {
            int l = max(1, i - a[i]), r = min(n, i + a[i]);
            b[l]++; b[r + 1]--;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1], a[i] = b[i];
            if (a[i] == n) cnt++;  
        }
        if (cnt == n) ok = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}