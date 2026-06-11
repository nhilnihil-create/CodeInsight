#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    int ans = 99999;
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            ans = min(ans, a[i] + a[j]);
        }
    }
    cout << ans;

    return 0;
}