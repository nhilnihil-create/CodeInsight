#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N; ll K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) --A[i];
    vector<int> ord(N, -1);
    int way = 0, cir = 1;
    vector<int> ans;
    int cur = 0;
    while (ord[cur] == -1) {
        ord[cur] = sz(ans);
        ans.push_back(cur);
        cur = A[cur];
    }
    way = ord[cur];
    cir = sz(ans) - way;
    if (way >= K) cout << ans[K] + 1 << '\n';
    else {
        K -= way;
        K %= cir;
        cout << ans[way + K] + 1 << '\n';
    }
    return 0;
}
