#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int l = 1, r = 1e9;
    int ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i]-1) / m;
        }
        if (sum > k) {
            l = m + 1;
        }
        else {
            ans = m;
            r = m - 1;
        }
    }
    cout << ans;

    return 0;
}