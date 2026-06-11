#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    vector<int> good(N, 1);
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        --A; --B;
        if (H[A] >= H[B]) good[B] = 0;
        if (H[A] <= H[B]) good[A] = 0;
    }
    int ans = accumulate(good.begin(), good.end(), 0);
    cout << ans << '\n';
    return 0;
}