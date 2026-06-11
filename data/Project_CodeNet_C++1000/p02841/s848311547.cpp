#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll M1, D1, M2, D2;
    cin >> M1 >> D1 >> M2 >> D2;
    if(M1 + 1 == M2) PRINT("1");
    else PRINT("0");
    return 0;   
}