/* 参考 */
/* https://drken1215.hatenablog.com/entry/2020/03/08/020200 */

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

int main(){
    int n, p;
    string s;
    cin >> n  >> p >> s;

    if(p == 2 || p == 5) {
        ll ans = 0;
        REP(i, n) {
            if((s[n - 1 - i] - '0') % p == 0) {
                ans += n - i;
            }
        }

        cout << ans << endl;
        return 0;
    }

    vector<long long> val(p, 0);    /* あまりが0 - p-1になる数 */
    ll ten_ruijo_amari = 1;
    ll cur = 0;
    val[cur]++;

    REP(i, n) {
        cur = (cur + (s[n - 1 - i] - '0') * ten_ruijo_amari) % p;
        ten_ruijo_amari = (ten_ruijo_amari * 10) % p;
        val[cur]++;
    }

    ll ans = 0;
    REP(i, p) ans += val[i] * (val[i] - 1) / 2;

    cout << ans << endl;

    return 0;
}