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

int get_zeroes(int n) {
    int zeroes = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x) {
            int d = x % 10;
            if (d == 0) zeroes++;
            else break;
            x /= 10;
        }
    }
    return zeroes;
}


int main() {
    long long n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    long long div = 10;
    while (n / div > 0) {
        ans += n / div;
        div *= 5;
    }
    cout << ans << endl;

    return 0;
}