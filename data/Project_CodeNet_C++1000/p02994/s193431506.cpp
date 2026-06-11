#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, l;
    cin >> n >> l;
    int taste = 0, ans;
    for (int i = 0; i < n; i++) {
        taste += l + i;
    }
    if (l > 0) {
        ans = taste - l;
    } else if (l + n > 0) {
        ans = taste;
    } else {
        ans = taste + abs(l + n - 1);
    }
    cout << ans << endl;
    return 0;
}