#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    int ans = min(A, K);
    K -= min(A, K);
    if (K > 0) {
        K -= min(B, K);
    }
    if (K > 0) {
        ans -= K;
    }
    cout << ans << '\n';
    return 0;
}