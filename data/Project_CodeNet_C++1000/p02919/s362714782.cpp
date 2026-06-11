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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int p[100010], q[100010];
    rep(i, N) cin >> p[i];
    rep(i, N) p[i]--;
    rep(i, N) q[p[i]] = i;
    multiset<int> L, R;
    L.insert(-1);
    L.insert(-1);
    R.insert(N);
    R.insert(N);
    ll ans = 0;
    RREP(i, N - 2, 0) {
        L.insert(q[i + 1]);
        R.insert(q[i + 1]);
        auto itrL = L.lower_bound(q[i]);
        auto itrR = R.lower_bound(q[i]);
        ll x2 = *(--itrL);
        ll x1 = *(--itrL);
        ll x3 = *(itrR);
        ll x4 = *(++itrR);
        //cout << x1 << " " << x2 << " " << q[i]<< " " << x3 << " " << x4 << endl;
        ans += ((i + 1) * (x2 - x1) * (x3 - q[i]));
        ans += ((i + 1) * (q[i] - x2) * (x4 - x3));
    }
    cout << ans << endl;



    return 0;
}
