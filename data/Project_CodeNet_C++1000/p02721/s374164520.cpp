
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
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    int sa = INF;
    int idx = 0;

    /* 左から */
    REP(i, n) {
        if(idx == k) break;
        if(s[i] == 'x') {
            sa++;
            continue;
        }
        if(c <= sa) {
            sa = 0;
            l[idx] = i;
            idx++;
        } else {
            sa++;
        }
    }

    /* 右から */
    sa = INF, idx = 0;
    REP_REV(i, n) {
        if(idx == k) break;
        if(s[i] == 'x') {
            sa++; continue;
        }
        if(c <= sa) {
            sa = 0;
            r[idx] = i;
            idx++;
        } else {
            sa++;
        }
    }

    //REP(i, k) cout << l[i] << " " << r[k-1-i] << endl;

    REP(i, k) {
        if(l[i] == r[k-1-i]) cout << l[i] + 1 << endl;
    }

    return 0;
}