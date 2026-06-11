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
bool broken[100010];
int dp[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    
    rep(i, M) {
        int a; cin >> a;
        broken[a] = true;
    }
    dp[0] = 1;
    rep(i, N + 1) {
        if(!broken[i + 1]) dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        if(!broken[i + 2]) dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
    }
    //rep(i, N + 1) cout << i << " " << dp[i] << endl;
    cout << dp[N] << endl;

    return 0;
}
