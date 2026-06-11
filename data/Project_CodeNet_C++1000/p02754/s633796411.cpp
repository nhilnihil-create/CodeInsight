#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = 0;
    ans += (n / (a + b)) * a;
    if (n % (a + b) != 0) {
        ans += min((n % (a + b)),a);
    }
    cout << ans;

    return 0;
}