#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll T1, T2, A1, A2, B1, B2;

signed main(){
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    if(A1 > B1){
        swap(A1, B1);
        swap(A2, B2);
    }
    if(A1 == B1 && B1 > B2){

    }
    if(A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2){
        PRINT("infinity");
        return 0;
    }
    if(A1 * T1 + A2 * T2 < B1 * T1 + B2 * T2){
        PRINT(0);
        return 0;
    }
    ll d = A1 * T1 + A2 * T2 - (B1 * T1 + B2 * T2);
    ll m = T1 * (B1 - A1);
    ll n = m / d;
    PRINT(2 * n + (n * d != m));
    return 0;
}