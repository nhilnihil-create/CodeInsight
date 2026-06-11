#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long l, r;
    cin >> l >> r;

    if ((r+1 - l) >= 2019) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 2020;
    for (long long i = l; i <= r; i++) {
        for (long long j = i+1; j <= r; j++) {
            ans = min(ans, (i*j)%2019);
        }
    }

    cout << ans << endl;
    return 0;
}
