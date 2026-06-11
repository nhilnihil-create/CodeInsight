#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // カードの枚数をsortして大きい数のものを減らしていく
    // 累積和
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        int x;
        cin >> x;
        A[x-1]++;
    }
    sort(A.begin(), A.end());
    vector<int> Acum(N+1);
    rep(i, N) {
        Acum[i+1] = Acum[i] + A[i];
    }
    int cur = N, ans = N;
    for (int k = 1; k <= N; k++) {
        while (1) {
            auto ok = [&](int c) {
                while (cur > 0 && A[cur-1] >= c) cur--;
                int temp = Acum[cur] + c * (N - cur);
                return (temp >= c * k);
            }(ans);
            if (ok) break;
            ans--;
        }
        cout << ans << '\n';
    }    
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}