#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int l[n];
    rep(i, n) cin >> l[i];
    sort(l, l + n);

    int ans = 0;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l[k] < l[i] + l[j]) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
