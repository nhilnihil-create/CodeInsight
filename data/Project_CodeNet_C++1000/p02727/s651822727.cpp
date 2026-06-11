#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    ll p[A];
    rep(i,A) cin >> p[i];
    ll q[B];
    rep(i,B) cin >> q[i];
    vector<ll> r;
    rep(i,C){
        ll R;
        cin >> R;
        r.push_back(R);
    }
    sort(p,p+A);
    sort(q,q+B);
    for(ll i=A-X;i<A;i++) r.push_back(p[i]);
    for(ll i=B-Y;i<B;i++) r.push_back(q[i]);
    sort(r.begin(),r.end());
    ll out = 0;
    rep(i,X+Y) out += r[X+Y+C-1-i];
    cout << out << endl;
    return 0;
}
