/* https://drken1215.hatenablog.com/entry/2020/01/26/234000 */
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
    ll n, d, a;
    cin >> n >> d >> a;

    vector<int> zahyo(n), kaisu(n);

    REP(i, n) {
        cin >> zahyo[i] >> kaisu[i];
        kaisu[i] = (kaisu[i] + (a-1)) / a;
    }

    vector<int> idx_(n);
    REP(i, n) idx_[i] = i;
    
    sort(ALL(idx_), [&](int i, int j) {
        return zahyo[i] < zahyo[j];});
    
    ll ans = 0;
    queue<P> que;
    ll num = 0;
    for(auto i: idx_) {
        while(!que.empty() && que.front().first < zahyo[i]) {
            num -= que.front().second;
            que.pop();
        }
        kaisu[i] -= num;
        if(kaisu[i] > 0) {
            ans += kaisu[i];
            que.push({zahyo[i] + 2 * d, kaisu[i]});
            num += kaisu[i];
        }
    }
    cout << ans << endl;
    
    
    return 0;
}