#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll n; cin >> n;
    // x[i]: 深さiで葉でない, sum[i]: a[i]までの累積和
    vector<ll> a(n+1), b(n+1, 0), sum(n+1, 0);
    rep(i, n+1) cin >> a[i];
    sum[0] = a[0];
    rep(i, n) {
        sum[i+1] = sum[i] + a[i+1];
    }
    ll ans = 0;

    bool ok = true;
    rep(i, n+1) {
        if(i == 0) {
            b[i] = 1-a[i];
            if(b[i] < 0) {
                ok = false;
                break;
            }
            ans++;
        }
        else {
            ll ub = min(2*b[i-1]-a[i], sum[n]-sum[i]);
            if(b[i-1]-a[i] > ub || ub < 0) {
                ok = false;
                break;
            }
            else {
                b[i] = ub;
                ans += (a[i] + b[i]);
            }
        }
    }

    if(ok) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
