#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A[100001];
ll dp[3];

ll solve(){
    ll ret = 1;
    REP(i, N){
        ll t = 0;
        REP(j, 3){
            if(A[i] == dp[j]){
                if(t == 0) dp[j]++;
                t++;
            }
        }
        ret = (ret * t) % MOD;
    }
    return ret;
}

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    PRINT(solve());
    return 0;
}