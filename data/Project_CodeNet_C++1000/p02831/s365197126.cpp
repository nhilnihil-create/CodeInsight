#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long a, b;
    scanf("%ld %ld", &a, &b);
    long x = a * b / gcd(a, b);
    printf("%ld\n", x);
}