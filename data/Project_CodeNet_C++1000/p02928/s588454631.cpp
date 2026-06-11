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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int A[2010];
    rep(i, N) cin >> A[i];
    int ans = 0;
    rep(i, N) {
        int cntL = 0, cntR = 0;
        rep(j, N) {
            if (i < j && A[i] > A[j]) cntR++;
            else if (j < i && A[i] > A[j]) cntL++;
        }
        int tmpL = (cntL * (((K) * (K - 1)/2) % mod)) % mod;
        int tmpR = (cntR * (((K * (K + 1)) / 2) % mod)) % mod;
        ans = (ans + tmpL + tmpR) % mod;
        //cout << i << " " << cntL << " " << cntR << " "  << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
// 2 1 2 1 2 1
