#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A.at(i) >> B.at(i);

    vector<vector<ll> > dp(N+1, vector<ll>(H+1, INF));
    dp[0][0] = 0;
    rep(i, N){
        rep(j, H+1){
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(j+A[i], H)], dp[i+1][j] + B[i]);
        }
    }
    cout << dp[N][H] << endl;
}