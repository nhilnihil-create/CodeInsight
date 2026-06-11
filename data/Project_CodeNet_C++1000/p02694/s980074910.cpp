#include <bits/stdc++.h>

using namespace std;

const long long N = 1e18;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long x, c = 100, ans = 0;
    cin >> x;
    while(c < x) {
        c += c / 100;
        ans++;
    }

    cout << ans << endl;
}
