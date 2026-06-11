#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, K;
    string S;
    cin >> N >> K >> S;
    ll group = 1;
    REP(i, N - 1){
        if(S[i] != S[i + 1]) group++;
    }
    while(K > 0 && group > 2){
        group -= 2;
        K--;
    }
    if(group == 2 && K > 0) group = 1;
    PRINT(N - group);
    return 0;
}