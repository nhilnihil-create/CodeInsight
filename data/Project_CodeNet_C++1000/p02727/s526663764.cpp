#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.rbegin(),p.rend());
    sort(r.rbegin(),r.rend());
    sort(q.rbegin(),q.rend());

    vector<ll> s;
    for(int i = 0; i < x; i++) s.pb(p[i]);
    for(int i = 0; i < y; i++) s.pb(q[i]);
    for(int i = 0; i < c; i++) s.pb(r[i]);
    sort(s.rbegin(),s.rend());

    ll ans = 0;
    rep(i,x+y) ans += s[i];
    cout << ans << endl;
}
