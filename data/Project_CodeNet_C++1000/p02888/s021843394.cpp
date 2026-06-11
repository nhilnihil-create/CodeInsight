#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // cout << "i " << i << " j " << j << endl;
            int val = v[i] + v[j];
            // cout << "val " << val << endl;
            auto it = lower_bound(v.begin() + j + 1, v.end(), val);
            int idx = it - v.begin() - 1;
            if (idx <= j) continue;
            // cout << "idx " << idx << endl;
            sum += max(0, idx - j);
            // cout << "sum " << sum << endl;
        }
    }
    cout << sum << endl;
}