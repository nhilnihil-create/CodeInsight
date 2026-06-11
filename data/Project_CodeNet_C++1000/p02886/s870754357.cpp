#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += a[i] * a[j];
        }
    }
    cout << ans;
    return 0;
}