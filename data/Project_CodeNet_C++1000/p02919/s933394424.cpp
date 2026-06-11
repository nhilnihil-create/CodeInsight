#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    vector<P> l;
    rep(i, N) l.pb(P(A[i], i));
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    
    multiset<int> s = {-1, -1, N, N};
    int ans = 0;
    rep(i, N) {
        P p = l[i];
        int value = p.first, idx = p.second;
        if (i>0) {
            int prepre = *----s.lower_bound(idx);
            int pre = *--s.lower_bound(idx);
            int nex = *s.lower_bound(idx);
            int nexnex = *++s.lower_bound(idx);
            ans += value*((idx-pre)*(nexnex-nex)+(nex-idx)*(pre-prepre));
        }
        s.insert(idx);
    }
    
    cout << ans << endl;
}