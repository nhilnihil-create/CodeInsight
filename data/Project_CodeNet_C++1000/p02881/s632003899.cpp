#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

vector<pair<long long, long long>> P;

void fill(long long n) {
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            P.push_back(make_pair(i, n / i));
        }
    }
}


int main() {
    long long n;
    cin >> n;
    fill(n);
    long long ans = INF;
    for (auto p : P) {
        ans = min(ans, p.first - 1 + p.second - 1);
    }
    cout << ans;
    return 0;
}