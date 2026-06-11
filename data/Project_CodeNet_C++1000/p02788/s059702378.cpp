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

pair<int, int> p[200010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, D, A;
    cin >> N >> D >> A;
    int ans = 0;
    
    vector<int> X(N), H(N);
    rep(i, N) {
        cin >> X[i] >> H[i];
        p[i] = {X[i], H[i]};
    }
    sort(p, p + N);
    sort(X.begin(), X.end());
    rep(i, N) {
        int cnt = max(0LL, (p[i].second + A - 1 - sum[i])) / A;
        ans += cnt;
        sum[i + 1] += cnt * A + sum[i];
        sum[distance(X.begin(), upper_bound(X.begin(), X.end(), X[i] + D * 2))] -= cnt * A;
        //cout << "*" << sum[i] << endl;
    }
    cout << ans << endl;
    

    return 0;
}
