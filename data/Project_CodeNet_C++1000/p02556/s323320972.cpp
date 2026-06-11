#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int main() {
    int n;
    cin >> n;
    int mi1 = 1e9, mi2 = 1e9, mx1 = -1e9, mx2 = -1e9;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mi1 = min(mi1, x - y);
        mi2 = min(mi2, x + y);
        mx1 = max(mx1, x - y);
        mx2 = max(mx2, x + y);
    }
    cout << max(mx1 - mi1, mx2 - mi2) << endl;
    return 0;
}
