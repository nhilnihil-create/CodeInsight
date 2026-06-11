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


int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll l = t1 * (b1 - a1);
    ll d = t2 * (b2 - a2) + l;

    if(d == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    if ((l > 0 && d > 0) || (l < 0 && d < 0)){
        cout << 0 << endl;
        return 0;
    }

    l = abs(l);
    d = abs(d);

    if (l % d != 0) cout << 2 * (l/d) + 1 << endl;
    else cout << 2*(l/d) << endl;

    return 0;
}
