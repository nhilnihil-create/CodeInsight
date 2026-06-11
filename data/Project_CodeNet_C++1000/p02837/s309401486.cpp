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

int x[20][20], y[20][20];
int a[20];

int main(){
    int n;
    cin >> n;


    rep(i, n){
        int p; cin >> p;
        a[i] = p;
        rep(j, p) {
            int c, d;
            cin >> c >> d;
            c--;
            x[i][j] = c;
            y[i][j] = d;
        }
    }

    int ans = 0;

    for(int bits = 0; bits < (1<<n); bits++){
        bool flag = 1;
        rep(i, n){
            if (!(bits&(1<<i))) continue;
            rep(j, a[i]){
                if ((1 & (bits>>x[i][j])) ^ y[i][j]) flag = 0;
            }
        }
        if (flag) ans = max(ans, __builtin_popcount(bits));
    }

    cout << ans << endl;

    return 0;
}
