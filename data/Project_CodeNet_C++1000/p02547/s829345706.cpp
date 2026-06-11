#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int d1, d2, ct = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &d1, &d2);
        if (d1 == d2) {
            ++ct;
            if (ct == 3) {
                break;
            }
        } else {
            ct = 0;
        }
    }
    if (ct == 3) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}