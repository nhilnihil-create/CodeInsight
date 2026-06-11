#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int ans = 0;
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    int Amaxi = A[N - 1];
    vector<int> dp(Amaxi + 1, 1);
    rep(i, N) { //各Aiについて
        int p = A[i];
        if(dp[p] == 1) {
            rep(q, (Amaxi / p) + 1) dp[p * q] = 0;
            if(A[i] != A[i + 1]) {
                ans += 1;
            }
        }
    }
    if(dp[Amaxi] == 1) {
        ans += 1;
    }
    cout << ans << endl;
}