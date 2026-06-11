#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int A, B, N;
    cin >> A >> B >> N;
    int ans = -1;
    int x = min(B - 1, N);
    while (true) {
        int cur = (A * x) / B - A * (x / B);
        ans = max(ans, cur);
        ++x;
        break;
    }
    cout << ans;
}
//x=100*(1 + 0.01*n)