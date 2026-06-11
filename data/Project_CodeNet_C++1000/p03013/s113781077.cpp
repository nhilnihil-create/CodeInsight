#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;
int main()
{
    int N, M;
    cin >> N >> M;
    set<int> st;
    rep(i, M) {
        int A;
        cin >> A;
        st.insert(A);
    }

    vector<ll> dp(N + 2);
    dp[0] = 1;
    rep(i, N) {
        if (st.count(i + 1) == 0) {
            dp[i + 1] += dp[i];
            dp[i + 1] %= MOD;
        }
        if (st.count(i + 2) == 0) {
            dp[i + 2] += dp[i];
            dp[i + 2] %= MOD;
        }
    }

    cout << dp[N] % MOD << endl;
    return 0;
}