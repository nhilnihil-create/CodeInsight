#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

ll n, k, a[200010];
inline void solve(int T) {

    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    ll l = 1, r = 1e9;
    while(l < r) {
        ll mid = (l + r) / 2, tmp = 0;
        rep(i, 1, n) if(a[i] > mid) {
            ll f = ceil(1.0 * a[i] / mid);
            tmp += f - 1;
        }
        if(tmp > k) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}   
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
 
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
    // system("pause");
}