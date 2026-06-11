#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for (size_t i = 0; i < n; i++) cin >> l[i];

    int ans = 0;
    int d = 0;
    for (size_t i = 0; i < n; i++) {
        if (d <= x) ans++;
        d += l[i];
    }
    if (d <= x) ans++;

    cout << ans << endl;
    return 0;
}
