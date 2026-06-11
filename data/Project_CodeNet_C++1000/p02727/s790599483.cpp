#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    priority_queue<int> q1, q2, q3;
    int ans = 0;
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    rep(i, A) {int p; cin >> p; q1.push(p);}
    rep(i, B) {int p; cin >> p; q2.push(p);}
    rep(i, C) {int p; cin >> p; q3.push(p);}
    rep(i, X) {int p = q1.top(); q1.pop(); q3.push(p);}
    rep(i, Y) {int p = q2.top(); q2.pop(); q3.push(p);}
    rep(i, X + Y) {int p = q3.top(); q3.pop(); ans += p;}
    cout << ans << endl;

    return 0;
}
