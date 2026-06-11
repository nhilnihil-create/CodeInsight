#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x; cin >> x;
    int ans = 1;
    int X = x;
    while (X% 360 != 0) {
        X += x;
        ans++;
    }
    cout << ans << endl;
}