#include <bits/stdc++.h>

using namespace std;

long long solve(long long v) {
    if (v == 1) return 1;
    return 2LL * solve(v / 2) + 1LL;
}

int main() {
    long long h;
    scanf("%lld", &h);

    printf("%lld\n", solve(h));
}
