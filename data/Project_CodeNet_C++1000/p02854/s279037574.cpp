#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int64_t a[n];
    int64_t sum_length = 0;
    rep(i,n) {
        cin >> a[i];
        sum_length += a[i];
    }
    int64_t left_length = 0;
    int64_t ans = sum_length;
    rep(i,n-1) {
        left_length += a[i];
        ans = min(abs(left_length - (sum_length - left_length)), ans);
    }
    cout << ans << endl;
}