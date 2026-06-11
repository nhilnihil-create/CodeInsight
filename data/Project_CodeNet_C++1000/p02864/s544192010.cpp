#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

long long dp[333][333][333];

int main(){
    REP(i, 333) REP(j, 333) REP(k, 333) dp[i][j][k] = 1LL<<60;
    dp[0][0][0] = 0;

    int N, K;
    cin >> N >> K;
    vector<int> H(N+1);
    REP(i, N) cin >> H[i+1];
    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=N; k++){
                dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
                dp[i+1][j][i+1] = min(dp[i+1][j][i+1], dp[i][j][k] + H[i+1] - min(H[k], H[i+1]));
            }
        }
    }
    long long ans = 1LL<<60;
    for(int j=0; j<=K; j++)
        for(int k=0; k<=N; k++)
            ans = min(ans, dp[N][j][k]);
    cout << ans << endl;
    return 0;
}