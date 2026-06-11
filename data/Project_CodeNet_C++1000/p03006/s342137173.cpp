#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, x[100], y[100];
map<pll, ll> mp;

signed main(){
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];
    REP(i, N){
        REP(j, N){
            if(i == j) continue;
            mp[pll(x[i] - x[j], y[i] - y[j])]++;
        }
    }
    ll m = 0;
    for(auto p : mp) m = max(m, p.second);
    PRINT(max(1LL, N - m));
    return 0;
}