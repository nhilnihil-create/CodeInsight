#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x;
    cin >> x;
    long long a = 100;
    int ans = 0;
    while (a < x) {
        a += a / 100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
