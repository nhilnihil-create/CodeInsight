#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int main() {
    int m, d;
    cin >> m >> d;
    int ans = 0;
    rep(i, 1, m) {
        rep(j, 2, 9) {
            if(i%j == 0 && j*10+i/j <= d && i/j > 1 && i/j <= 9) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}