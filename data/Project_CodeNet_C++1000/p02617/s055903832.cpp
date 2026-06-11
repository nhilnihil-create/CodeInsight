#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;


signed main() {
    int N;
    cin >> N;
    int ans = N * (N + 1) * (N + 2) / 6;
    rep(i, N - 1) {
        int l, r;
        cin >> l >> r;
        if (l > r)swap(l, r);
        ans -= l * (N + 1 - r);
    }
    cout << ans << endl;
    return 0;
}
