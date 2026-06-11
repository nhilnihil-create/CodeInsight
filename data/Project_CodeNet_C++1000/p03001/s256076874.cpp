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
vector<int> get_divisors(long long n) {
    vector<int> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
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
    long long W, H, x, y;
    cin >> W >> H >> x >> y;
    long double area = (long double)((long double)W * H) / 2;
    cout << area;
    if (W == x * 2 && H == y * 2) {
        cout << " " << 1;
    }
    else {
        cout << " " << 0;
    }
    return 0;
}