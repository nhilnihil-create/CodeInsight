#include<iostream>
#include<vector>

using namespace std;
const long long MOD = 1000000007LL;

int main() {
    long long n, k; cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = n-1; i >= 0; --i) {
        long long num = 0;
        for (int j = n-1; j > i; --j) {
            if (a[i] > a[j]) {
                ++num;
            }
        }
        ans = (ans + num * k) % MOD;
    }
    const long long p = (k-1) * k / 2 % MOD;
    for (int i = 0; i < n; ++i) {
        long long num = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i] > a[j]) {
                ++num;
            }
        }
        ans = (ans + num * p) % MOD;
    }
    cout << ans << endl;
    return 0;
}