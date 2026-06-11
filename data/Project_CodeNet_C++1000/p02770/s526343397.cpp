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
    int k, q;
    cin >> k >> q;
    int d[5010];
    rep(i, k) cin >> d[i];
    while(q--) {
        int n, x, m;
        cin >> n >> x >> m;
        int d2[5010];
        int N = n;
        rep(i, k) d2[i] = (d[i] + m - 1) % m + 1;
        // rep(i, k) cout << d2[i] << " ";
        // cout << endl;
        rep(i, k - 1) d2[i + 1] += d2[i];
        x = x % m;
        x += (n - 1)/k * d2[k - 1];
        n -= (n - 1)/k * k;
        // cout << x << " ";
        rep(i, n - 1) x += (d[i] + m - 1) % m + 1;
        // cout << x << " ";
        cout << N - x/m - 1 << endl;
    }

    return 0;
}
