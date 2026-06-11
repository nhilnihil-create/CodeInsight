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
    vector<int> A(102, 0);
    rep(i, N) {
        int p;
        cin >> p;
        A[p] = 1;
    }
    P ans(999, -1);
    for (int i = 0; i <= 101; i++) {
        if (A[i] == 1) continue;
        int diff = abs(i - X);
        ans = min(ans, P(diff, i));
    }
    cout << ans.second << '\n';
    return 0;
}