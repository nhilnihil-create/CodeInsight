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
    int n; cin >> n;
    int h[100010];
    rep(i, n) cin >> h[i];
    int maximam[100010];
    int minimam[100010];
    maximam[0] = 0;
    minimam[n] = INF;
    rep(i, n) maximam[i + 1] = max(maximam[i], h[i]);
    rep(i, n) minimam[n - i - 1] = min(minimam[n - i], h[n - i - 1]);
    // rep(i, n + 1) cout << maximam[i] << " ";
    // cout << endl;
    // rep(i, n + 1) cout << minimam[i] << " ";
    // cout << endl;
    rep(i, n + 1) {
        if(maximam[i] > minimam[i] + 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl; 

    return 0;
}
