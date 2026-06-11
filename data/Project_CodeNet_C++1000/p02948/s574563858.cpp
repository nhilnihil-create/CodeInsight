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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(100001);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    priority_queue<int> q;
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        for (auto it : a[i]) q.emplace(it);
        if (!q.empty()) {
            sum += q.top();
            q.pop();
        }
    }
    cout << sum;
    return 0;
}