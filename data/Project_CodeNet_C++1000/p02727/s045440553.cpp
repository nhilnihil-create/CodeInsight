#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    for(ll i=0;i<a;i++) cin >> p[i];
    for(ll i=0;i<b;i++) cin >> q[i];
    for(ll i=0;i<c;i++) cin >> r[i];
    sort(ALL(p),greater<ll>());
    sort(ALL(q),greater<ll>());
    sort(ALL(r),greater<ll>());

    priority_queue<ll> que;
    for(ll i=0;i<x;i++) que.push(p[i]);
    for(ll i=0;i<y;i++) que.push(q[i]);
    for(ll i=0;i<c;i++) que.push(r[i]);

    ll ans = 0;
    for(ll i=0;i<x+y;i++){
        ll cur = que.top();
        ans += cur;
        que.pop();
    }

    cout << ans << endl;

    return 0;
}