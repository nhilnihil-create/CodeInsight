#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

bool isPrime(long long x) {
    if (x == 1) return true;
    for (long long i = 2; i*i <= x; i++) {
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

bool is_sorted(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) return false;
    }
    return true;
}

int mxN = 1e5;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n);
    int i = 0;
    while (i < n) {
        bool odd = false;
        int cnt = 0;
        int pos = -1;
        while (s[i] == 'R') {
            i++; cnt++;
        }
        pos = i - 1;
        if (cnt % 2) odd = true;
        while (i < n && s[i] == 'L') {
            i++; cnt++;
        }
        if (cnt % 2) {
            if (odd) {
                a[pos] = (cnt / 2) + 1;
                a[pos + 1] = cnt / 2;
            }
            else {
                a[pos+1] = (cnt / 2) + 1;
                a[pos] = cnt / 2;
            }
        }
        else {
            a[pos] = cnt / 2;
            a[pos + 1] = cnt / 2;
        }

    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}