#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    scanf("%lld%lld.%lld", &a, &b, &c);

    printf("%lld\n", a * b + a * c / 100);

    return 0;
}