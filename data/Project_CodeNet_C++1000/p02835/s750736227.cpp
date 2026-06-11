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
    int a, a1, a2;
    cin >> a >> a1 >> a2;
    if (a + a1 + a2 >= 22) {
        cout << "bust";
    }
    else {
        cout << "win";
    }

    return 0;
}