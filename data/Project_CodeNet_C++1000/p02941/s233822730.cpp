#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpl = vector<pll>;
using vvll = vector<vll>;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(ll i=0;i<((ll)n);i++)
#define REP1(i,n) for(ll i=1;i<((ll)n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


//abc173
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vll a(n), b(n);
    REP(i, n)cin >> a[i];
    REP(i, n)cin >> b[i];

    ll cor_num = 0;
    ll ans = 0;
    while (cor_num!=n) {
        bool flag = true;
        REP(i, n) {
            ll d = b[(n + i - 1) % n];
            ll e = b[i];
            ll f = b[(i + 1) % n];

            if (e < a[i]) {
                cout << -1 << endl;
                return 0;
            }

            if (d + f < e)
                flag = false;
            if ((e - a[i]) % (d + f) == 0) {
                ans += (e - a[i]) / (d + f);
                b[i] = a[i];
            }
            else {
                ans += e / (d + f);
                b[i] = e % (d + f);
            }
        }

        bool ok = true;
        REP(i, n)if (a[i] != b[i])ok = false;
        if (ok)break;

        if (flag) {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
}


