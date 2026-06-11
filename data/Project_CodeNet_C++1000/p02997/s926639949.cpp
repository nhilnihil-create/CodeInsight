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
    int n, k;
    cin >> n >> k;

    if(k > (n-1) * (n-2) / 2) {
        cout << "-1" << endl;
        return 0;
    }

    int muda = (n-1) * (n-2) / 2 - k;
    cout <<  n-1 + muda << endl;

    REPN(i, 1, n) {
        cout << 1 << " " << i+1 << endl;
    }

    if(muda == 0) return 0;
    int idx = 0;
    REPN(i, 1, n) REPN(j, i+1, n) {
        cout << i+1 << " " << j+1 << endl;
        
        idx++;
        if(idx == muda) return 0;
    }
    

    return 0;
}