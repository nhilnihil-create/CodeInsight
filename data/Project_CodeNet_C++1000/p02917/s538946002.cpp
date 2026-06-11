#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (size_t i = 0; i < n-1; i++) cin >> b[i];

    a[n-1] = b[n-2];
    for (int i = n-2; i > 0; i--) {
        if (b[i-1] <= b[i]) a[i] = b[i-1];
        else a[i] = b[i];
    }
    a[0] = b[0];

    int ans = 0;
    for (size_t i = 0; i < n; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}
