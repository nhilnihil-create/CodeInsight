#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<Int> a(n);
    Int sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }

    Int minv = sum;
    Int left_sum = 0;
    rep(i, n) {
        left_sum += a[i];
        minv = min(minv, abs(left_sum-(sum-left_sum)));
    }
    cout << minv << endl;
}