#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];

int main () {
    int n; scanf("%d", &n);
    int xor_sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        xor_sum ^= a[i];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", xor_sum ^ a[i], " \n"[i == n]);
    }
}
