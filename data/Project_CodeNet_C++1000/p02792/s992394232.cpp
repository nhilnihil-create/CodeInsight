#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, mp[10][10];

signed main(){
    cin >> N;
    FOR(i, 1, N + 1){
        string str = to_string(i);
        mp[str.front() - '0'][str.back() - '0']++;
    }
    ll ans = 0;
    REP(i, 10){
        REP(j, 10){
            ans += mp[i][j] * mp[j][i];
        }
    }
    PRINT(ans);
    return 0;
}