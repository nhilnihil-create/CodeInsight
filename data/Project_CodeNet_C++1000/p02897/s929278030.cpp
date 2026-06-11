#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    double p = 0, o = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2) o++;
        else p++;
    }
    cout << fixed << setprecision(10) << (o / n);

    return 0;
}