#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, ans = (long long int)1e18;
    cin >> n;
    int a[n];
    long long int L = 0;
    long long int cut[n+1] = {0};
    for(int i = 0 ; i < n; ++i) {
        cin >> a[i];
        L += a[i];
        cut[i+1] = L;
    }
    for(int i = 0; i < n; ++i) {
        ans = min(ans, abs(cut[i] - (L - cut[i])));
    }

    cout << ans << '\n';

    return 0;
}
