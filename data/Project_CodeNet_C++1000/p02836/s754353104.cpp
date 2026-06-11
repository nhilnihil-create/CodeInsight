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
    string s;
    cin >> s;
    int n = s.length();
    int i = 0; int j = n - 1;
    int cnt = 0;
    while (i < j) {
        if (s[i++] != s[j--]) cnt++;
    }
    cout << cnt;
    return 0;
}