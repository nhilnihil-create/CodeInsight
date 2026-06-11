#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt[3];
    for (int i = 0; i < 3; i++) {
        cnt[i] = 0;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int k = 0;
        int m;
        for (int j = 0; j < 3; j++) {
            if (cnt[j] == a[i]) {
                k++;
                m = j;
            }
        }
        if (k == 0) {
            cout << 0 << endl;
            return 0;
        }
        ans = ans * k % mod;
        cnt[m]++;
    }

    cout << ans << endl;
    return 0;
}