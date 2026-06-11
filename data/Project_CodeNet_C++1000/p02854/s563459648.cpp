#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    cin >> N;

    long long a[200000 + 5];
    long long tot = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        tot += a[i];
    }

    long long ans = tot, tmp = 0;
    for (int i = 1; i <= N; i++) {
        tmp += a[i];
        ans = min(ans, abs(tmp - (tot - tmp)));
    }
    cout << ans << endl;
    return 0;
}