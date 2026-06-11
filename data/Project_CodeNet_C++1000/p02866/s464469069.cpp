#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}
int main() {
    ll n; cin >> n;
    vector<ll> d;
    ll mod = 998244353;
    ll mn = 1e10;
    ll mx = -1;
    set<ll> st;
    ll a[100001]; INITA(a, 0, 100000, 0);
    REP(i, n) {
        ll tmp;
        cin >> tmp;
        d.push_back(tmp);
        mn = min(mn, tmp);
        mx = max(mx, tmp);
        st.insert(tmp);
        a[tmp]++;

        if (i != 0 && tmp == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    // 0 1 1 2
    // 1 -> 2 -> 4
    //   -> 3

    // 1 -> 3 -> 4
    //   -> 2

    // 0 1 1 2 2 2 3
    // 24
    // 2 について、選び方は 2^3
    // その次に3は3^1
    // FOR(i, 0, mx) {
    //     cout << a[i] << endl;
    // }

    if ((d[0] != 0) || ((ll) st.size() != mx + 1)) {
        // できないのはいつ？
        // d[0]が1でない、あるいは0が複数、あるいは番号が飛んでいる
        // 0が複数パターンはinput時点で対応している
        cout << 0 << endl;
    } else {
        ll res = 1;
        FOR(i, 2, mx) {
            // res *= (ll) pow(a[i-1], a[i]) % mod;
            REP(j, a[i]) {
                res *= a[i-1] % mod;
                res %= mod;
            }
        }
        cout << res << endl;
    }

    return 0;
}