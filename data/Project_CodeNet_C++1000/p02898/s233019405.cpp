#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (h >= k) ans++;
    }

    cout << ans << endl;
    return 0;
}
