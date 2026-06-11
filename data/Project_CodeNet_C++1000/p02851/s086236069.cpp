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
    int N, K;
    cin >> N >> K;
    int A[200010];
    rep(i, N) cin >> A[i];
    rep(i, N) A[i] = (A[i] - 1) % K;

    int sum[200010] = {};
    rep(i, N) sum[i + 1] = (sum[i] + A[i]) % K;
    map<int, int> mp;
    rep(i, min(N, K - 1)) mp[sum[i + 1]]++;
    // rep(i, N + 1) cout << sum[i] << " ";
    // cout << endl;
    int ans = 0;
    int c = 0;
    rep(i, N) {
        
        ans += mp[c];
        if(i + K <= N) mp[sum[i + K]]++;
        mp[sum[i + 1]]--;
        //cout << i << " " << c << " " << ans << endl;
        c = (c + A[i]) % K;
    }
    cout << ans << endl;
    return 0;
}
// 0 3 1 2 4

