#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    
    vector<vector<int>> dp1(N+1, vector<int>(T)), dp2(N+1, vector<int>(T));
    rep(i, N) {
        rep(j, T) {
            chmax(dp1[i+1][j], dp1[i][j]);
            if (j + A[i] < T) chmax(dp1[i+1][j+A[i]], dp1[i][j] + B[i]);
        }
    }

    repr(i, N) {
        rep(j, T) {
            chmax(dp2[i][j], dp2[i+1][j]);
            if (j + A[i] < T) chmax(dp2[i][j+A[i]], dp2[i+1][j] + B[i]);
        }
    }

    int ans = 0;
    rep(i, N) {
        rep(j, T) {
            chmax(ans, dp1[i][j] + dp2[i+1][T-1-j] + B[i]);
        }
    }

    cout << ans << endl;
}