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
    int A[100010];
    rep(i, n) cin >> A[i];
    int ans[100010] = {}; 
    int ok = INF / 2;
    int ng = -1;
    while(abs(ok - ng) > 1) {
        int mid = ((ok + ng) / 2) * 2;
        //mid = 2;
        ans[0] = mid;
        int tmp[100010] = {};
        tmp[0] += mid / 2;
        tmp[n - 1] += mid / 2;
        rep(i, n - 1) {
            int c = (A[i] - tmp[i]);
            ans[i + 1] = c * 2;
            tmp[i + 1] += c;
            tmp[i] += c;
        }
        // rep(i, n) cout << tmp[i] << " ";
        // cout << endl;
        if(tmp[n - 1] >= A[n - 1]) ok = mid / 2;
        else ng = mid / 2;
        //cout << ok << " " << ng << endl;
        //break;
    }
    ans[0] = ok * 2;
    int tmp[100010] = {};
    tmp[0] += ok;
    tmp[n - 1] += ok;
    rep(i, n - 1) {
        int c = (A[i] - tmp[i]);
        ans[i + 1] = c * 2;
        tmp[i + 1] += c;
        tmp[i] += c;
    }
    rep(i, n) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

// x[0] = x[1] + x[N - 1]
