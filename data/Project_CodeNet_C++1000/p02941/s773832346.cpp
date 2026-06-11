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
#define INF 1000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
typedef pair<int, int> P;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    int A[200010], B[200010];
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    int ans = 0;
    while(true) {
        bool change = false;
        rep(i, N) {
            if(A[i] == B[i]) continue;
            int a = B[(i - 1 + N) % N];
            int b = B[i];
            int c = B[(i + 1) % N];
            int ok = 0;
            int ng = INF;
            while(abs(ok - ng) > 1) {
                int mid = (ok + ng) / 2;
                if(b - (a + c) * mid >= A[i]) ok = mid;
                else ng = mid;
            }
            if(ok == 0) continue;
            change = true;
            B[i] = b - (a + c) * ok;
            ans += ok;
        }
        // rep(i, N) cout << B[i] << " ";
        // cout << endl;
        if(!change) break;
    }
    rep(i, N) {
        if(A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;


    return 0;
}
