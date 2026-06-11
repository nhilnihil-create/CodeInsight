#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int a, b;
    cin >> a >> b;
    int ans = a - b * 2;
    if (ans < 0) {
        cout << 0;
    }
    else {
        cout << ans;
    }
    return 0;
}