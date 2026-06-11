#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define REP(i, x, n) for(ll (i)=(x); (i)<(n); (i)++)
#define RREP(i, x, n) for(ll (i)=(n)-1; (i)>=x; (i)--)
#define FOR(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define RFOR(i, n) for(ll (i)=(n)-1; (i)>=0; (i)--)

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        ll N, S, ans = 0;
        const ll mod = 998244353;
        cin >> N >> S;
        vector<ll> A(N);
        FOR(i, N) cin >> A[i];
        vector<vector<ll> > dp(N+1, vector<ll>(S+1, 0));
        dp[0][0] = 1;
        FOR(i, N) {
                FOR(w, S+1) {
                        dp[i+1][w] += 2 * dp[i][w];
                        dp[i+1][w] %= mod;
                        if (w + A[i] <= S) {
                                dp[i+1][w + A[i]] += dp[i][w];
                                dp[i+1][w + A[i]] %= mod;
                        }
                }
        }
        cout << dp[N][S] << endl;

        return 0;
}