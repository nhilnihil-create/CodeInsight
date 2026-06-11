#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

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

int main() {
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == 'Z') s[j] = 'A';
            else s[j] = (char)((int)s[j] + 1);
        }
    }
    cout << s;

    return 0;
}