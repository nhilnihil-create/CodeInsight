#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
const ll MOD = 1e9+7;
const int inf = -10000;

void debug_vector(vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve();
int main(void){

    solve();
    return 0;
}

void solve(){
    string S, T;
    cin >> S >> T;
    int N, M;
    N = S.size();
    M = T.size();
    // dp[i][j] := S[i], T[j]まで見たときの編集距離
    // ans = dp[N][M]
    int dp[1010][1010] = {0};
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) dp[i][0] = i;
    for (int j = 0; j <= M; j++) dp[0][j] = j;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            int c = 1;
            if (S[i-1] == T[j-1]) c = 0;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + c});
        }
    }
    cout << dp[N][M] << endl;
}

