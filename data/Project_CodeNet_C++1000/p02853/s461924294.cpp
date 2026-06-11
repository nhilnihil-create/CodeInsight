#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    vector<int> a(2);
    REP(i, 2) cin >> a[i];
    int ans = 0;

    REP(i, 2) {
        if(a[i] == 1) {
            ans += 300000;
        } else if(a[i] == 2) {
            ans += 200000;
        } else if(a[i] == 3){
            ans += 100000;
        }
    }

    if(a[0] == 1 && a[1] == 1) {
        ans += 400000;
    }

    cout << ans << endl;

    return 0;
}