#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> cand(N, 1);
    rep(i, K) {
        int d;
        cin >> d;
        rep(i, d) {
            int a;
            cin >> a;
            --a;
            cand[a] = 0;
        }
    }
    int ans = 0;
    rep(i, N) ans += cand[i];
    cout << ans << '\n';
    return 0;
}