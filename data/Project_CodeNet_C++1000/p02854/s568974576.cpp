#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<long> a(n);
    rep(i, n) cin >> a[i];
    long m = INT64_MAX;
    long sum = 0;
    rep(i, n) sum += a[i];
    long left = a[0];
    long right = sum - left;
    m = abs(right - left);
    for(int i = 1; i < n; i++) {
        left += a[i];
        right -= a[i];
        m = min(m,abs(left - right));
    }
    cout << m << endl;
}