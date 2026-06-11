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
    int N; cin >> N;
    int P[100100];
    int _P[100010];
    rep(i, N) cin >> P[i];
    rep(i, N) _P[P[i]] = i + 1;
    multiset<int> S, T;
    S.insert(0); S.insert(0);
    T.insert(N + 1); T.insert(N + 1);
    int ans = 0;
    RREP(i, N, 1) {
        auto itr1 = T.upper_bound(_P[i]);
        int y = *itr1;
        int z = *(++itr1);

        auto itr2 = S.lower_bound(_P[i]);
        int x = *(--itr2);
        int w = *(--itr2);
        S.insert(_P[i]);
        T.insert(_P[i]);

        ans += (x - w) * (y - _P[i]) * i;
        ans += (_P[i] - x) * (z - y) * i;
        //cout << w <<  " " << x << " " << _P[i] << " " << y << " " << z << " " << ans << endl;
    }
    cout << ans << endl;



    return 0;
}
