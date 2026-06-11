#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

ll N, T;
vector<pll> v;
ll A[3001], B[3001];
ll dp[6001][6001];

ll solve(){
    REP(i, N){
        REP(t, T + 1){
            dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
            if(t < T) dp[i + 1][min(t + A[i], T)] = max(dp[i + 1][min(t + A[i], T)], dp[i][t] + B[i]);
        }
    }
    ll ret = 0;
    REP(t, T + 1) ret = max(ret, dp[N][t]);
    return ret;
}

signed main(){
    cin >> N >> T;
    ll a, b;
    REP(i, N){
        cin >> a >> b;
        v.push_back(pll(a, -b));
    }
    sort(ALL(v));
    REP(i, N){
        A[i] = v[i].first;
        B[i] = -v[i].second;
    }
    PRINT(solve());
    return 0;
}