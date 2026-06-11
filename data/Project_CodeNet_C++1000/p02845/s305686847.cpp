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
    bool ok = true;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 1, num = 0; // 答え、列の数
    map<ll, ll> m; // 最後尾の数とその数
    
    rep(i, n) {
        if(a[i] == 0) {
            num++;
            if(m.count(0)) {
                m[0]++;
                if(m[0] > 3) {
                    ok = false;
                    break;
                }
            }
            else m[0] = 1;
        }
        else {
            ans = mtime(ans, m[a[i]-1], 1);
            m[a[i]-1]--;
            if(m[a[i]-1] < 0) {
                ok = false;
                break;
            }
            if(m.count(a[i])) {
                m[a[i]]++;
                if(m[a[i]]>3) {
                    ok = false;
                    break;
                }
            }
            else m[a[i]] = 1;
        }
    }

    if(num >= 4) {
        ok = false;
    }
    else if(num >= 2) {
        ans = mtime(ans, 6, 1);
    }
    else {
        ans = mtime(ans, 3, 1);
    }
    if(ok) cout << ans << endl;
    else cout << 0 << endl;

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
