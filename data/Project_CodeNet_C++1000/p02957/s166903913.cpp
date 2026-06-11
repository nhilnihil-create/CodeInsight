#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

int main() {
    long long a, b;
    cin >> a >> b;
    long long sum = a + b;
    if (sum % 2) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << sum / 2;
    }

    return 0;
}