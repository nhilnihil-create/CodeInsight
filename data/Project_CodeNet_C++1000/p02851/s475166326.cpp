#include "bits/stdc++.h"
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
int sum[200010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int A[200010];
    rep(i, N) cin >> A[i];
    rep(i, N) A[i]--;
    rep(i, N) A[i] %= K;
    rep(i, N) {
        sum[i + 1] = (sum[i] + A[i]) % K;
    }
    // rep(i, N + 1) cout << sum[i] << " ";
    // cout << endl;
    map<int, int> mp;
   rep(i, min(N + 1, K)) {
        mp[sum[i]]++;
    }
    int ans = 0;
    rep(i, N) {
        ans += mp[sum[i]] - 1;
        mp[sum[i]]--;
        if (i + K <= N) mp[sum[i + K]]++;
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
//  1 4 2 3 5
//  0 3 1 2 4
//0 0 3 4 6 10

//4 2 4 2 4 2 4 2
//  3 1 3 1 3 1 3 1
//0 3 4 7 8 11 12 15 16

//  14 15 92 65 35 89 79 32 38 46
//  6  0  0  1  6  4  1  3  2  3
//0 6  6  6  7  13 17 18 21 23 26 
//  x        x
//     X
//     x  x
//     x        x
//        X
//        x     x
//           x  x
//              x         x