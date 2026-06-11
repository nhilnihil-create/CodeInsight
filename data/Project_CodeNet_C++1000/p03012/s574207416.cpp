#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N, ans = 1000000007;
    cin >> N;
    vector<long long> W(N), W_sum(N+1,0);
    rep(i, N){
        cin >> W[i];
    }

    // 累積和の作成
    rep(i,N) {
        W_sum[i+1] = W_sum[i] + W[i];
        // cout << W_sum[i+1] << " ";
    }
    // cout << endl;

    for(int i = 1; i <= N+1; ++i) {
        ans = min(ans, abs((W_sum[N] - W_sum[i]) - W_sum[i])); 
        // cout << ans << " ";
    }
    // cout << endl;

    cout << ans << endl;
    return 0;
}
