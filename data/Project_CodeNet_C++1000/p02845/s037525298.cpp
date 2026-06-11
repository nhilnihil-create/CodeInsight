#include <bits/stdc++.h>
using namespace std;

const int kMod = 1'000'000'000 + 7;

int main() {
    int n; scanf("%d", &n);
    int c[3] = {0, 0, 0}, ans = 1;
    for (int i = 0; i < n; ++i) {
        int a, v = 0; scanf("%d", &a);
        for (int j = 0; j < 3; ++j) v += c[j] == a;
        ans = 1LL * ans * v % kMod;
        for (int j = 0; j < 3; ++j) {
            if (c[j] == a) {
                c[j]++;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
