#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x,n;
    cin >> x >> n;
    if (n == 0) {
        cout << x << endl;
        return 0;
    }
    vector<int> p(102);
    rep(i, n) cin >> p[i];
    int dist = x;
    int ans =0;
    for (int i = 0; i <= 101; ++i) {
        auto itr = find(ALL(p), i);
        if (itr != p.end()) continue;
        if (dist > abs(x-i)) {
            dist = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}