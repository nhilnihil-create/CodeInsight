#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define ld          long double
#define endl        "\n"

const int mod = 1e9+7;

inline int add(int a, int b) { int res = a + b; if(res >= mod) res -= mod;  return res; }
inline int sub(int a, int b) { int res = a - b; if(res < 0) res += mod; return res;}
inline int mul(int a, int b) { return (a * b)%mod; }

void solve() {  
    int n; cin >> n;
    int pos[n+1]; pos[0] = 0;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 0;
    multiset<int> s;
    s.insert(0); s.insert(0);
    s.insert(n+1); s.insert(n+1);
    s.insert(pos[n]);
    for(int cur=n-1; cur>0; cur--) {
        int l1, l2, r1, r2;
        int cp = pos[cur];
        auto it = s.lower_bound(cp); 
        r1 = *it; 
        auto it2 = it;
        it2++;
        r2 = *it2;
        it2 = (--it);
        l1 = *it2;
        l2 = *(--it2);
        //cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        ans += cur * ((cp-l1)*(r2-r1) + (l1-l2)*(r1-cp));
        s.insert(cp);
    }
    cout << ans << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(18);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}