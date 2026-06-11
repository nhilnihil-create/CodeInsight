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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int x[15][15], y[15][15];
    int A[15];
    rep(i, N) {
        cin >> A[i];
        rep(j, A[i]) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int ans = 0;
    rep(bit, (1 << N)) {
        bool ok = true;
        int tmp = 0;
        rep(i, N) {
            if(!(bit & (1 << i))) continue;
            tmp++;
            rep(j, A[i]) {
                bool state = !(!((1 << x[i][j]) & bit));
                if(state != y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
