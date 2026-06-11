#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int mx = 2e5 + 9;

int a[mx];

int main() {
    int n; scanf("%d", &n);
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s ^= a[i];
    }

    for (int i = 0; i < n; i++) a[i] = s ^ a[i];
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
}