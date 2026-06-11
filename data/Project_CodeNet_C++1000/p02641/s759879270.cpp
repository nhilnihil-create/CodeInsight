#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int X, N;
    cin >> X >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    int ans = -100;
    for (int i = 0; i <= 101; i++) {
        if (count(P.begin(), P.end(), i)) continue;
        if (abs(ans - X) > abs(i - X)) ans = i;
    }
    cout << ans << '\n';
    return 0;
}