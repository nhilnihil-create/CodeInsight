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

    Int left_sum = 0;
    Int half = sum/2;
    Int i;
    for (i = 0; i < n; i++) {
        left_sum += a[i];
        if (half - left_sum == 0) {
            cout << 0 << endl;
            return 0;
        }
        else if (half - left_sum < 0) {
            break;
        }
    }

    Int minv = 0;
    if (i != 0) {
        minv = min(left_sum-(sum-left_sum),(sum-(left_sum-a[i])) - (left_sum-a[i]) );
    }
    else {
        minv = left_sum-(sum-left_sum);
    }
    cout << minv << endl;
}