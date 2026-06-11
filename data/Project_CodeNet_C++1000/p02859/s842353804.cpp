#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MX = 1e9;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
long long digits(long long m) {
    long long cnt = 0;
    while (m) {
        cnt++;
        m /= 10;
    }
    return cnt;
}



int main() {
    long long n;
    cin >> n;
    cout << n * n;


    return 0;
}