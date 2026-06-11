#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) (x).begin(),(x).end()
#define Ceil(x, n) (((((x))+((n)-1))/n))
#define CeilN(x, n) (((((x))+((n)-1))/n)*n)

#define INF 2e7
#define INF_LL 1LL<<60
#define ll long long
typedef pair<ll, ll>    P;

int main(){
    ll h, w, m;
    cin >> h >> w >> m;
    vector<ll> yoko(h), tate(w);
    vector<P> bomb(m);

    REP(i, h) yoko[i] = 0;
    REP(i, w) tate[i] = 0;

    REP(i, m) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        yoko[x]++, tate[y]++;
        bomb[i].first = x, bomb[i].second = y;
    }

    ll yoko_max = 0, tate_max = 0, yoko_max_num = 0, tate_max_num = 0;
    REP(i, h) yoko_max = max(yoko_max, yoko[i]);
    REP(i, w) tate_max = max(tate_max, tate[i]);

    REP(i, h) if(yoko_max == yoko[i]) yoko_max_num++;
    REP(i, w) if(tate_max == tate[i]) tate_max_num++;

    ll num = yoko_max_num * tate_max_num;

    REP(i, m) {
        int x = bomb[i].first;
        int y = bomb[i].second;
        if(yoko[x] == yoko_max && tate[y] == tate_max) {
            num--;
        }
    }

    ll ans = 0;

    if(num > 0) {
        ans = yoko_max + tate_max;
    } else {
        ans = yoko_max + tate_max - 1; 
    }

    cout << ans << endl;

    return 0;
}
