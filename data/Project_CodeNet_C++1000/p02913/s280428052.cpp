#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    vec<vec<int>> dp(N + 1, vec<int>(N + 1, 0));

    for(int i=N-1;i>=0;--i) for(int j=N-1;j>=0;--j) {
        if (i == j) continue;
        if (S[i] == S[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
    }

    int ans = 0;
    rep(i,N)rep(j,N){
        if(i<j&&i+dp[i][j]<=j) ans=max(ans,dp[i][j]);
    }
    cout << ans << endl;
}