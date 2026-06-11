// Date: 2020-05-31

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define IO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define D(x) cout << #x << " = " << x << endl;
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int a[N];
int main() {
    FIO;
    int n;
    cin >> n;
    LL sum = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i];
    if(n == 0) {
        if(a[0] == 1) cout << 1;
        else cout << -1;
        return 0;
    }
    if(a[0]) {
        cout << -1;
        return 0;
    }
    LL ans = 1, nl = 1;
    int flag = 1;
    rep(i, 1, n) {
        LL m = min(2*nl, sum);
        if(m < a[i]) {
            flag = 0;
            break;
        }
        ans += m;
        nl = m-a[i];
        sum -= a[i];
    }
    if(!flag) ans = -1;
    cout << ans;

    return 0;
}