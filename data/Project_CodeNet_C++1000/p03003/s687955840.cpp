#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> S(N), T(M);
    for(auto& x: S) cin >> x;
    for(auto& x: T) cin >> x;

    const ll MOD = 1e9+7;
    Vvec<ll> dp(N+1, vector<ll>(M+1));
    for(int i=0; i<=N; i++) dp[i][0] = 1;
    for(int j=0; j<=M; j++) dp[0][j] = 1;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(S[i-1] == T[j-1]) dp[i][j] += dp[i-1][j-1];
            dp[i][j] += MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[N][M] << endl;
}