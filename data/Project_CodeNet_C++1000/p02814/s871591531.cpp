#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

long long gcd(long long a, long long b){
    while (a != 0 && b != 0){
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

ll N, M, a[100010];

signed main(){
    cin >> N >> M;
    REP(i, N) cin >> a[i];
    ll L = 1;
    REP(i, N){
        L = lcm(L, a[i] / 2);
        if(L < 0){
            PRINT(0);
            return 0;
        }
    }
    REP(i, N){
        if(L / (a[i] / 2) % 2 != L / (a[0] / 2) % 2){
            PRINT(0);
            return 0;
        }  
    }
    if(M < L) PRINT(0);
    else PRINT((M - L) / (2 * L) + 1);
    return 0;
}