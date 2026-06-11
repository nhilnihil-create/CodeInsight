#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll A[6] = {100, 101, 102, 103, 104, 105};
bool dp[100001];

bool solve(ll X){
    dp[0] = true;
    REP(i, 6){
        REP(j, 100001){
            if(j + A[i] > 100000) continue;
            dp[j + A[i]] |= dp[j];
        }
    }
    return dp[X];
}

signed main(){
    ll X;
    cin >> X;
    if(solve(X)) PRINT("1");
    else PRINT("0");
    return 0;
}