#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N;
string S;
bool dp1[10], dp2[100], dp3[1000];

signed main(){
    cin >> N >> S;
    REP(i, N){
        ll n = S[i] - '0';
        REP(j, 100) dp3[j * 10 + n] |= dp2[j];
        REP(j, 10) dp2[j * 10 + n] |= dp1[j];
        dp1[n] = true;
    }
    ll ans = 0;
    REP(i, 1000) ans += (dp3[i] == true);
    //REP(i, 10) if(dp1[i]) cerr << i << " "; cerr << endl;
    //REP(i, 100) if(dp2[i]) cerr << i << " "; cerr << endl;
    //REP(i, 1000) if(dp3[i]) cerr << i << " "; cerr << endl;
    PRINT(ans);
    return 0;
}