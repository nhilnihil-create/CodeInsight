#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b;

    scanf("%lld%lld", &a, &b);

    if((a & 1) != (b & 1)) {
        puts("IMPOSSIBLE");
    } else {
        printf("%lld\n", (a + b) >> 1);
    }

    return 0;
}
