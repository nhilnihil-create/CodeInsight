#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n-1);
    for (size_t i = 0; i < n; i++) cin >> a[i];
    for (size_t i = 0; i < n; i++) cin >> b[i];
    for (size_t i = 0; i < n-1; i++) cin >> c[i];

    int ans = 0;
    int pre = -1;
    for (size_t i = 0; i < n; i++) {
        ans += b[a[i]-1];
        if (a[i]-1 == pre) ans += c[a[i]-2];
        pre = a[i];
    }

    cout << ans << endl;
    return 0;
}
