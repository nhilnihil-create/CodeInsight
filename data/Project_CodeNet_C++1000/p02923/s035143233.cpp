#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int INF = 1000000001;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    rep(i, n) {
        scanf("%d", &h[i]);
    }
    // int len = 1;
    // vector<int> l(n+1, INF);
    // rep(i, n) {
    //     if (i == 0) {
    //         l[len] = h[i];
    //         continue;
    //     }
    //     if (h[i] <= l[len]) {
    //         len++;
    //         l[len] = h[i];
    //     } else {
    //         int ng = 0, ok = len;
    //         while (ng + 1 < ok) {
    //             int mid = (ng + ok) / 2;
    //             if (h[i] > l[mid]) {
    //                 ok = mid;
    //             } else {
    //                 ng = mid;
    //             }
    //         }
    //         l[ok] = h[i];
    //     }
    // }
    // printf("%d\n", len);
    int cnt = 0, max_c = 0;
    rep(i, n-1) {
        if (h[i] >= h[i+1]) {
            cnt++;
            max_c = max(max_c, cnt);
        } else {
            cnt = 0;
        }
    }
    printf("%d\n", max_c);
}