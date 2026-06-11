#include <bits/stdc++.h>

using namespace std;


constexpr long long mod = 1000000007;
constexpr long long INF = mod * mod;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    long long ans = INF;
    long long range_sum = 0;
    for(int i = 0; i < n; i++) {
        range_sum += a[i];
        ans = min(ans, abs(range_sum - (sum - range_sum)));
    }
    cout << ans << "\n";
    return 0;
}