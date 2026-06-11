#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1000000007;
int dp[100005];

int main() {
    int N, M; cin >> N >> M;
    vector<int> S(N+1);
    rep(i, M){
        int a; cin >> a;
        S[a] = 1;
    }

    dp[0] = 1;
    for (int i = 0; i < N; i++){
        if(S[i+1] != 1){
            dp[i+1] += dp[i];
            dp[i+1] %= mod;
        }
        if(S[i+2] != 1){
            dp[i+2] += dp[i];
            dp[i+2] %= mod;
        }
    }

    cout << dp[N] << endl;

    return 0;
}