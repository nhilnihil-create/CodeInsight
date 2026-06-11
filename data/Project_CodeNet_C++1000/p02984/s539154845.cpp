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
int ans[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    rep(i, N) {
        if(i % 2 == 0) ans[0] += A[i];
        else ans[0] -= A[i];
    }
    REP(i, 1, N - 1) ans[i] = 2 * A[i - 1] - ans[i - 1];
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
// 2A[0] = ans[0] + ans[1];
// 2A[1] = ans[1] + ans[2];
// 2A[2] = ans[2] + ans[0];

// ans[0] = 2A[0] - ans[1]
//        = 2A[0] - (2A[1] - ans[2])
//        = 2A[0] - (2A[1] - (2A[2] - ans[0]))
//        = 2A[0] - 2A[1] + 2A[2] - ans[0];
// ans[0] = A[0] - A[1] + A[2]
