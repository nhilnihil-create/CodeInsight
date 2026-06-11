#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

bool isPrime(long long x) {
    if (x == 1) return true;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

vector<long long> common_divisors(long long a, long long b) {
    long long n = gcd(a, b);
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 0; i < (int)s.length(); i++) {
        if (i % 2 == 0) {
            if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D') ok = false;
        }
        else {
            if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D') ok = false;
        }
    }
    if (ok) cout << "Yes";
    else cout << "No";
    return 0;
}