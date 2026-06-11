#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    ll p[A];
    ll q[B];
    ll r[C + X + Y];
    rep(i, A){
        cin >> p[i];
    }
    rep(i, B){
        cin >> q[i];
    }
    sort(p, p + A, greater<ll>());
    sort(q, q + B, greater<ll>());
    rep(i, C){
        cin >> r[i];
    }
    for(ll i = C; i < C + X; i++){
        r[i] = p[i - C];
    }
    for(ll i = C + X; i < C + X + Y; i++){
        r[i] = q[i - C - X];
    }
    sort(r, r + C + X + Y, greater<ll>());

    ll ans = 0;
    rep(i, X + Y){
        ans += r[i];
    }

    cout << ans << endl;

    return 0;
}
