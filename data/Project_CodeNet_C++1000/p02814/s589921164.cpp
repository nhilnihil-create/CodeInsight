#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};

//ユークリッドの互除法
ll gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

//3項以上の場合
ll gcd(vector<ll>a) {
  int ans = a[0];
  for (int i=1; i<sz(a); i++) {
    ans = gcd(ans, a[i]);
  }
  return ans;
}

ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int f(int x) {
    int res = 0;
    while (x%2==0) {
        x /= 2;
        res++;
    }
    return res;
}

int main() {
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    rep(i,n) {
        a[i] /= 2;
    }

    int t = f(a[0]);
    rep(i,n) {
        if (f(a[i]) != t) {
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    }
    m>>=t;

    ll l = 1;
    rep(i,n) {
        l = lcm(l, a[i]);
        if (l>m) {
            cout << 0 << endl;
            return 0;
        }
    }

    m /= l;
    int ans = (m+1)/2;
    cout << ans << endl;

    // int cnt = 0; //因数2の個数
    // ll num = 2;
    // ll tmp = 2;
    // while (a[0]%tmp==0) {
    //     cnt++;
    //     tmp *= 2;
    // }
    // //tmp /= 2;

    // rep(i,n-1) { //存在するか判定
    //     num = 2;
    //     while (a[i+1]%num==0) {
    //         num *= 2;
    //     }
    //     if (num != tmp) {
    //         cout << 0 << endl;
    //         return 0;
    //     }
    // }

    // ll GCD = gcd(a);
    // rep(i,n) a[i] /= GCD;
    // ll LCM = GCD;
    // set<ll> st;
    // rep(i,n) st.insert(a[i]);
    // for (ll x : st) LCM *= x;
    // LCM /= 2;

    // ll ans = 0;
    // for (ll i=1;;i+=2) {
    //     ll tmp2 = LCM;
    //     tmp2 *= i;
    //     if (tmp2 > m) break;
    //     ans++;
    // }
    // cout << ans << endl;
}