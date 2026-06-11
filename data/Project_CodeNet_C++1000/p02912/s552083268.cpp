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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << (int)(a[0] / pow(2, k));
        return 0;
    }
    sort(a.rbegin(), a.rend());
    while (k) {
        while (k && a[0] >= a[1]) {
            a[0] /= 2;
            k--;
        }
        int temp = a[0];
        a.erase(a.begin(), a.begin() + 1);
        int l  = 0, h = n - 2;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (a[m] > temp) {
                l = m+1;
            }
            else {
                h = m-1;
            }
        }
        a.insert(a.begin() + l, temp);
    }
    
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum;
    return 0;
}