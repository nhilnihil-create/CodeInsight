#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

long long gcd(long long a, long long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long long lcm(long long a, long long b)
{
    long long temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main() {
    long long a, b;
    cin >> a >> b;
    long long ans = lcm(a, b);
    cout << ans;
    return 0;
}