#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll p[100010], pos[100010];

int main(){
    int n;
    cin >> n;
    rep(i, n){
        cin >> p[i];
        pos[p[i]] = i+1;
    }

    multiset<ll> st= {0, 0, n+1, n+1};
    ll ans = 0;

    for(ll i = n; i > 0; i--){
        st.insert(pos[i]);
        auto it = st.lower_bound(pos[i]);
        auto l = prev(it);
        auto ll = prev(l);
        auto r = next(it);
        auto rr = next(r);
        ans += ((*l - *ll) * (*r - *it) + (*it - *l) * (*rr - *r)) * i;
    }

    cout << ans << endl;

    return 0;
}
